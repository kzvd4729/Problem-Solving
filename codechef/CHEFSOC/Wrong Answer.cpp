/****************************************************************************************
*  @author: kzvd4729                                         created: 05-03-2019 17:44:35                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 16M                                  
*  problem: https://www.codechef.com/MARCH19A/problems/CHEFSOC
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5+10;
const int mod=1e9+7;
int aa[N+2],n,dp[N+2],tw[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    memset(dp,0,sizeof(dp));cin>>n;dp[n]=1;
    for(int i=1;i<=n;i++)cin>>aa[i];
    if(aa[n]==1)tw[n]=n;else tw[n]=n+1;
    for(int i=n-1;i>=1;i--)
    {
      if(aa[i]==1)tw[i]=i;else tw[i]=tw[i+1];
      dp[i]=1;
      if(aa[i]==2&&i<n-1)
      {
        int ad=tw[i+2]-(i+2);
        if(ad%2==0&&tw[i+2]<=n)ad++;
        dp[i]+=ad;
      }
      dp[i]=(dp[i]+dp[i+1])%mod;
      if(aa[i]==2)dp[i]=(dp[i]+dp[i+2])%mod;
      if(aa[i]==2&&aa[i+1]==2)
        dp[i]=(dp[i]+dp[i+3])%mod;
    }
    cout<<dp[1]<<endl;
  }
  return 0;
}