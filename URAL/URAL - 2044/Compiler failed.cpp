/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-05 16:44:00                      
*  solution_verdict: Compiler failed                         language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/URAL-2044
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
    dp[p]={(int)s.size(),(int)s.size()};
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;init();build(s);

  for(int i=1;i<=s.size();i++)
  {
    long msk=0;
    for(int j=dp[i].first;j<=min(32,i);j+=2)msk|=(1LL<<(j-1));
    for(int j=dp[i].second;j<=min(32,i);j+=2)msk|=(1LL<<(j-1));
    cout<<msk<<'\n';
  }
  return 0;
}