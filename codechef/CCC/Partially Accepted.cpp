/****************************************************************************************
*  @author: kzvd4729                                         created: 08-07-2019 20:46:22                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 22.5M                                
*  problem: https://www.codechef.com/JULY19A/problems/CCC
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const long inf=1e18;
long aa[N+2],dp[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)
      cin>>aa[i];
    sort(aa+1,aa+n+1);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=k;j++)
        dp[i][j]=inf;
    for(int i=n;i>=1;i--)
      dp[i][1]=aa[i]*(n-i+1);
    for(int i=n;i>=1;i--)
    {
      for(int j=2;j<=k;j++)
      {
        for(int l=i+1;l<=n;l++)
        {
          dp[i][j]=min(dp[i][j],aa[i]+(aa[l]-aa[i])*(n-i-j+1)+dp[l][j-1]);
        }
      }
    }
    long ans=inf;
    for(int i=1;i<=n;i++)
      ans=min(ans,dp[i][k]);
    cout<<ans<<"\n";
  }
  return 0;
}