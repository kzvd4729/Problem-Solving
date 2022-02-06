/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/11/2020 20:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 407500 KB                            
*  problem: https://codeforces.com/contest/730/problem/J
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2,inf=1e9;
int aa[N+2],bb[N+2],n,dp[N+2][N+2][N*N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;int nd=0;
  for(int i=1;i<=n;i++)cin>>aa[i],nd+=aa[i];
  for(int i=1;i<=n;i++)cin>>bb[i];
   for(int i=0;i<=n;i++)
  {
    for(int b=0;b<=n;b++)
      for(int cp=1;cp<=N*N;cp++)
        dp[i][b][cp]=-inf;
  }
  pair<int,int>ans={inf,inf};
  for(int i=1;i<=n;i++)
  {
    for(int b=1;b<=i;b++)
    {
      for(int cp=1;cp<=N*N;cp++)
      {
        dp[i][b][cp]=dp[i-1][b][cp];
        if(bb[i]<=cp)dp[i][b][cp]=max(dp[i][b][cp],aa[i]+dp[i-1][b-1][cp-bb[i]]);
         if(cp>=nd&&dp[i][b][cp]>0)
        {
          //cout<<cp<<" "<<i<<" "<<b<<" "<<dp[i][b][cp]<<endl;
          ans=min(ans,{b,nd-dp[i][b][cp]});
        }
      }
    }
  }
  cout<<ans.first<<" "<<ans.second<<endl;
  return 0;
}