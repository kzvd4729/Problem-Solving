/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2018 16:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 248 ms                                          memory_used: 11400 KB                             
*  problem: https://codeforces.com/contest/331/problem/C1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,dp[1000006],x,r;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(int i=0;i<=1000000;i++)dp[i]=1e9;
  cin>>n;
  dp[n]=0;
  for(int i=n;i>=0;i--)
  {
    x=i;
    while(x)
    {
      r=x%10;
      if(i-r>=0)dp[i-r]=min(dp[i-r],dp[i]+1);
      x/=10;
    }
  }
  cout<<dp[0]<<endl;
  return 0;
}