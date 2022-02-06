/****************************************************************************************
*  @author: kzvd4729                                         created: May/18/2018 13:47                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 311 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/466/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
long arr[N+2],sum,n,dp[N+2],ans,here;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    sum+=arr[i];
  }
  if(sum%3)cout<<0<<endl,exit(0);
  sum=sum/3;
  here=0;
  for(int i=n;i>=1;i--)
  {
    here+=arr[i];
    dp[i]=dp[i+1];
    if(here==sum)dp[i]++;
  }
  here=0;
  for(int i=1;i<=n;i++)
  {
    here+=arr[i];
    if(here==sum)
      ans+=dp[i+2];
  }
  cout<<ans<<endl;
  return 0;
}