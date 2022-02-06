/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/08/2020 19:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 436 ms                                          memory_used: 128800 KB                            
*  problem: https://codeforces.com/gym/102460/problem/J
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2,inf=1e9;
int mask[N+2],n,m,dp[N+2][(1<<16)+2];
int dfs(int i,int msk)
{
  if(i==n)return 0;
  if(dp[i][msk]!=-1)return dp[i][msk];
  int now=inf;
  if(msk&mask[i])now=dfs(i+1,msk);
  else
  {
    for(int j=0;j<m;j++)
    {
      if(mask[i]&(1<<j))
        now=min(now,1+dfs(i+1,msk|(1<<j)));
    }
  }
  return dp[i][msk]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>m;memset(mask,0,sizeof(mask));
    for(int i=0;i<m;i++)
    {
      string s;cin>>s;
      for(int j=0;j<n;j++)
      {
        if(s[j]=='1')mask[j]|=(1<<i);
      }
    }
    memset(dp,-1,sizeof(dp));
    int ans=dfs(0,0);if(ans==inf)ans=-1;
    cout<<ans<<"\n";
  }
  return 0;
}