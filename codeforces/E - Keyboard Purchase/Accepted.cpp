/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/08/2019 21:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 327 ms                                          memory_used: 16100 KB                             
*  problem: https://codeforces.com/contest/1238/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int mt[22][22],n,m,aa[20+2],bb[20+2],pre[N+N+2],dp[N+N+2];
 int dfs(int msk)
{
  if(__builtin_popcount(msk)==20)return 0;
  if(dp[msk]!=-1)return dp[msk];
  int ad=pre[msk],now=1e9;
  for(int i=0;i<20;i++)
  {
    if(msk&(1<<i))continue;
    now=min(now,dfs(msk|(1<<i)));
  }
  return dp[msk]=now+ad;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;string s,t;cin>>s;
  for(auto x:s)
  {
    if(t.size()==0)t.push_back(x);
    else
    {
      if(t.back()!=x)t.push_back(x);
    }
  }
  s=t;n=s.size();
   for(int i=0;i<n-1;i++)
    mt[s[i]-'a'][s[i+1]-'a']++,mt[s[i+1]-'a'][s[i]-'a']++;
   for(int msk=1;msk<(1<<20);msk++)
  {
    int a=-1,b=-1;
    for(int j=0;j<20;j++)
    {
      if(msk&(1<<j))aa[++a]=j;
      else bb[++b]=j;
    }
    for(int j=0;j<=a;j++)
      for(int k=0;k<=b;k++)
        pre[msk]+=mt[aa[j]][bb[k]];
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0)<<endl;
  return 0;
}