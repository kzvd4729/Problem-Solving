/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-05 13:44:38                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1294                                       memory_used (MB): 16.8                            
*  problem: https://vjudge.net/problem/HDU-4426
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
#include<random>
#define long long long 
using namespace std;
const int N=2e5,mod=777777777;
int nw,last,occur[N+2];
struct node
{
  int next[26],len,link;
  int st,ed;
}pal[N+2];
void init()
{
  pal[0].link=0;pal[0].len=-1;//odd length root
  pal[1].link=0;pal[1].len=0;//even length root
  nw=1,last=1;
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
      pal[nw].ed=p-1;pal[nw].st=p-pal[nw].len;

      if(pal[nw].len==1)pal[nw].link=1;
      else pal[nw].link=pal[x].next[c];
    }
    last=pal[last].next[c];occur[last]++;
  }
}
void occurrences(void)
{
  for(int i=nw;i>=2;i--)occur[pal[i].link]+=occur[i];
}
int con[26+2],pw[N+2];
string s;
const int b=26;
struct hsh
{
  string s;vector<int>v;
  int makeHash(void)
  {
    int hs=0;
    for(auto x:s)
    {
      hs=(1LL*hs*b+con[x-'a'])%mod;
      v.push_back(hs);
    }
    return hs;
  }
  int segment(int lt,int rt)
  {
    int x=v[rt];if(!lt)return x;
    x=x-(1LL*v[lt-1]*pw[rt-lt+1])%mod;
    if(x<0)x+=mod;return x;
  }
  void clear()
  {
    v.clear();
  }
}hs;
void clear()
{
  for(int i=0;i<=nw;i++)
    memset(pal[i].next,0,sizeof(pal[i].next)),occur[i]=0;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]=1;
  for(int i=1;i<=N;i++)pw[i]=(pw[i-1]*26LL)%mod;

  int t;cin>>t;
  while(t--)
  {
    int n,q;cin>>n>>q;cin>>s;init();build(s);occurrences();

    while(q--)
    {
      long k;cin>>k;for(int i=0;i<26;i++)cin>>con[i];
      hs.clear();hs.s=s;hs.makeHash();
      vector<pair<int,int> >v;
      for(int i=2;i<=nw;i++)
        v.push_back({hs.segment(pal[i].st,(pal[i].st+pal[i].ed)/2),occur[i]});
      sort(v.begin(),v.end());
      //for(auto x:v)cout<<x.first<<endl;
      for(auto x:v)
      {
        k-=x.second;
        if(k<=0){cout<<x.first<<endl;break;}
      }
    }
    cout<<endl;clear();
  }
  return 0;
}