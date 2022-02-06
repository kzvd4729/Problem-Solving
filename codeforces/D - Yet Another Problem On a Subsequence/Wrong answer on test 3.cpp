/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/28/2018 16:02                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1000/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const long mod=998244353;
long dp[N+2];
int n,arr[N+2];
long dfs(int ii)
{
  if(ii>=n)return 0;
  if(dp[ii]!=-1)return dp[ii];
  long here=0;
  if(arr[ii]>0&&ii+arr[ii]<=n)here=1+dfs(ii+arr[ii]);
  here%=mod;
  here+=dfs(ii+1);
  here%=mod;
  return dp[ii]=here%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1)<<endl;
   return 0;
}