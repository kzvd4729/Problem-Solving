/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-05 17:14:48                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/URAL-1954
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#define long long long 
using namespace std;
const int N=3e5;

pair<int,int>dp[N+2];
int nw,last;
struct node
{
  int next[26],len,link;
  int dif,sLink;
  pair<int,int>tmp;
}pal[N+2];
void init()
{
  pal[0].link=0;pal[0].len=-1;//odd length root
  pal[1].link=0;pal[1].len=0;//even length root
  nw=1,last=1;dp[0]={N+2,0};
  for(int i=0;i<N+2;i++)pal[i].tmp={N+2,N+2};
  //last keeps track of the lps suffix of till inserted string
}
void build(string s)
{
  s="#"+s;
  for(int p=1;p<s.size();p++)
  {
    while(s[p-pal[last].len-1]!=s[p])last=pal[last].link;
    int x=pal[last].link,c=s[p]-'a';
    while(s[p-pal[x].len-1]!=s[p])x=pal[x].link;//finding suffix link
    if(!pal[last].next[c])
    {
      pal[last].next[c]=++nw;pal[nw].len=pal[last].len+2;
      if(pal[nw].len==1)pal[nw].link=1;
      else pal[nw].link=pal[x].next[c];

      last=pal[last].next[c];

      /****/
      int xx=pal[last].link;
      pal[last].dif=pal[last].len-pal[xx].len;
      if(pal[last].dif==pal[xx].dif)pal[last].sLink=pal[xx].sLink;
      else pal[last].sLink=last;

    }
    else last=pal[last].next[c];

    //cout<<p<<" "<<last<<endl;
    dp[p]={N+2,N+2};
    for(int j=last;pal[j].len>0; )
    {
      int sfl=pal[j].link,srl=pal[j].sLink;
      int slv=pal[srl].link;

      pal[j].tmp=dp[p-(pal[slv].len+pal[j].dif)];
      if(pal[j].dif==pal[sfl].dif)
      {
        pal[j].tmp.first=min(pal[j].tmp.first,pal[sfl].tmp.first);
        pal[j].tmp.second=min(pal[j].tmp.second,pal[sfl].tmp.second);
      }
      pair<int,int>vl=pal[j].tmp;
      dp[p].first=min(dp[p].first,vl.second+1);
      dp[p].second=min(dp[p].second,vl.first+1);
      j=slv;
    }
    //cout<<pal[last].tmp.first<<" "<<pal[last].tmp.second<<endl;
  }
}
//od[i] is largest palindromic substring centered at i;
vector<int>od;
//ev[i] is largest palindromic substring centered at i and i+1;
vector<int>ev;
void manacher(string s)
{
  int n=s.size();
  od.resize(n);
  for(int i=0,l=0,r=-1;i<n;i++)
  {
    int k=(i>r)?1:min(od[l+r-i],r-i+1);
    while(0<=i-k&&i+k<n&&s[i-k]==s[i+k])k++;
    od[i]=k--;
    if(i+k>r)l=i-k,r=i+k;
  }
  ev.resize(n);
  for(int i=0,l=0,r=-1;i<n;i++)
  {
    int k=(i>r)?0:min(ev[l+r-i+1],r-i+1);
    while(0<=i-k-1&&i+k<n&&s[i-k-1]==s[i+k])k++;
    ev[i]=k--;
    if(i+k>r)l=i-k-1,r=i+k;
  }
  for(int i=0;i<n;i++)od[i]=od[i]*2-1;
  ev.erase(ev.begin());
  for(int i=0;i<n-1;i++)ev[i]=ev[i]*2;
}
bool ck(int i,int j)
{
  i--,j--;
  if((j-i+1)%2)return od[(i+j)/2];
  else return ev[(i+j)/2];
}
vector<pair<int,int> >v;
void solve(int n)
{
  if(dp[n].first==1)
  {
    v.push_back({1,1});
    v.push_back({2,2});
    v.push_back({3,n-2});
    v.push_back({n-1,n-1});
    v.push_back({n,n});
    return ;
  }
  else
  {
    dp[0]={0,0};int p=n,f=0,now=dp[n].first;
    if(now==3)f=1;
    for(int i=n;i>=1;i--)
    {
      //cout<<i<<" "<<p<<" "<<ck(i,p)<<endl;
      //cout<<dp[i].first<<" "<<dp[i].second<<endl;
      if(ck(i,p)&&((dp[i-1].first==now-1)||(dp[i-1].second==now-1)))
      {
        if(p-i+1>=3&&f)
        {
          v.push_back({i,i});
          v.push_back({p,p});
          v.push_back({i+1,p-1});
          f=0;
        }
        else v.push_back({i,p});
        p=i-1;now--;
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;init();build(s);

  manacher(s);

  int n=s.size();
  if(dp[n].first>5)cout<<"NO"<<endl;
  else
  {
    cout<<"YES"<<endl;
    solve(n);sort(v.begin(),v.end());
    for(auto x:v)
      cout<<s.substr(x.first-1,x.second-x.first+1)<<endl;
  }
  return 0;
}