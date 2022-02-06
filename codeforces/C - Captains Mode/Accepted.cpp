/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 82100 KB                             
*  problem: https://codeforces.com/contest/377/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2;
int aa[N+2],n;
int dp[20][(1<<20)+2];
pair<char,int>pp[N+2];
int dfs(int st,int msk)
{
  if(st>=n)return 0;
  if(dp[st][msk]!=-1)return dp[st][msk];
  if(pp[st].second==1)
  {
    int now=-1e9;
    for(int i=0;i<n;i++)
    {
      if((msk&(1<<i)))continue;
      if(pp[st].first=='p')now=max(now,aa[i]+dfs(st+1,msk|(1<<i)));
      else now=max(now,dfs(st+1,msk|(1<<i)));
    }
    return dp[st][msk]=now;
  }
  else 
  {
    int now=1e9;
    for(int i=0;i<n;i++)
    {
      if((msk&(1<<i)))continue;
      if(pp[st].first=='p')now=min(now,aa[i]*(-1)+dfs(st+1,msk|(1<<i)));
      else now=min(now,dfs(st+1,msk|(1<<i)));
    }
    return dp[st][msk]=now;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>aa[i];
  sort(aa,aa+n,greater<int>());
  int m;cin>>m;n=min(n,m);
  for(int i=0;i<m;i++)
    cin>>pp[i].first>>pp[i].second;
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,0)<<endl;
   return 0;
}