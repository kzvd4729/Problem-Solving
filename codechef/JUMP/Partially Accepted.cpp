/****************************************************************************************
*  @author: kzvd4729                                         created: 19-07-2019 11:44:43                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.03 sec                                        memory_used: 24M                                  
*  problem: https://www.codechef.com/problems/JUMP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
long pp[N+2],aa[N+2],hh[N+2],dp[N+2];
const long inf=LLONG_MAX;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>pp[i];
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)cin>>hh[i];
  for(int i=1;i<=n;i++)dp[i]=inf;
  dp[1]=aa[1];
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<i;j++)
    {
      if(pp[j]<pp[i])
        dp[i]=min(dp[i],(hh[i]-hh[j])*(hh[i]-hh[j])+aa[i]+dp[j]);
    }
  }
  cout<<dp[n]<<endl;
  return 0;
}