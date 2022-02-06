/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/31/2020 20:19                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 109 ms                                          memory_used: 12300 KB                             
*  problem: https://codeforces.com/contest/1105/problem/E
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
const int N=1e6;
map<string,int>mp;
int on[20+2],tw[20+2],bd[N+2];
int dp1[(1<<20)+2],dp2[(1<<20)+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;int cnt=0;vector<int>bf;
  int hf=m/2;if(m==1)cout<<1<<endl,exit(0);
  for(int i=1;i<=n;i++)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      sort(bf.begin(),bf.end());
      bf.erase(unique(bf.begin(),bf.end()),bf.end());
      for(int j=0;j<bf.size();j++)
      {
        for(int k=j+1;k<bf.size();k++)
        {
          int a=bf[j],b=bf[k];if(a<b)swap(a,b);
          if(a<hf&&b<hf)on[a]|=(1<<b);
          else if(a>=hf&&b>=hf)tw[a-hf]|=(1<<(b-hf));
          else bd[b]|=(1<<(a-hf));
        }
      }
      bf.clear();
    }
    else 
    {
      string s;cin>>s;
      if(mp[s]==0)mp[s]=++cnt;
      bf.push_back(mp[s]-1);
    }
  }
  sort(bf.begin(),bf.end());
  bf.erase(unique(bf.begin(),bf.end()),bf.end());
  for(int j=0;j<bf.size();j++)
  {
    for(int k=j+1;k<bf.size();k++)
    {
      int a=bf[j],b=bf[k];if(a<b)swap(a,b);
      if(a<hf&&b<hf)on[a]|=(1<<b);
      else if(a>=hf&&b>=hf)tw[a-hf]|=(1<<(b-hf));
      else bd[b]|=(1<<(a-hf));
    }
  }
  for(int msk=1;msk<(1<<hf);msk++)
  {
    if(__builtin_popcount(msk)==1)dp1[msk]=1;
    else
    {
      int msb=31-__builtin_clz(msk);
      if((on[msb]&(msk^(1<<msb)))==0)dp1[msk]=dp1[msk^(1<<msb)];
    }
  }
  for(int msk=1;msk<(1<<(m-hf));msk++)
  {
    if(__builtin_popcount(msk)==1)dp2[msk]=1;
    else
    {
      int msb=31-__builtin_clz(msk);
      if((tw[msb]&(msk^(1<<msb)))==0)dp2[msk]=dp2[msk^(1<<msb)];
    }
    //if(dp2[msk])cout<<"**"<<msk<<endl;
  }
  for(int i=1;i<(1<<(m-hf));i++)
    if(dp2[i])dp2[i]=__builtin_popcount(i);
  for(int i=0;i<(m-hf);i++)
  {
    for(int msk=1;msk<(1<<(m-hf));msk++)
    {
      if(msk&(1<<i))
        dp2[msk]=max(dp2[msk],dp2[msk^(1<<i)]);
    }
  }
  int ans=dp2[(1<<(m-hf))-1];
  for(int i=1;i<(1<<hf);i++)
  {
    if(dp1[i]==0)continue;
    int msk=0;
    for(int j=0;j<hf;j++)
      if(i&(1<<j))msk|=bd[j];
    //cout<<msk<<endl;
    ans=max(ans,__builtin_popcount(i)+dp2[(((1<<(m-hf))-1)^msk)]);
  }
  cout<<ans<<endl;
  return 0;
}