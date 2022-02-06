/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/02/2018 19:46                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 34700 KB                             
*  problem: https://codeforces.com/contest/19/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e14;
long n,t[2002],c[2002],tt,dp[2002][2002],ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>t[i]>>c[i],tt+=c[i];
  for(int i=0;i<=2000;i++)for(int j=0;j<=2000;j++)dp[i][j]=inf;
  dp[0][0]=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=2000;j++)
    {
      dp[i][j]=dp[i-1][j];
      if(t[i]>j)continue;
      dp[i][j]=min(dp[i][j],dp[i-1][j-t[i]]+c[i]);
      //cout<<dp[i][j]<<endl;
    }
//    for(int j=0;j<=5;j++)cout<<dp[i][j]<<" ";
//    cout<<endl;
  }
//  cout<<"here "<<endl;
//  for(int i=1;i<=5;i++)cout<<dp[n][i]<<endl;
  ans=tt;
  for(int i=1;i<=n;i++)
  {
    for(int j=(n+1)/2;j<=2000;j++)
    {
      ans=min(ans,dp[i][j]);
    }
  }
  cout<<ans<<endl;
  return 0;
}