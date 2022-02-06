/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/06/2020 15:46                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 11500 KB                             
*  problem: https://codeforces.com/contest/1239/problem/A
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=1e6;
const int mod=1e9+7;
int dp[N+2][2];
int solve(int n)
{
  dp[0][0]=1,dp[0][1]=1,dp[1][0]=1,dp[1][1]=1;
  for(int i=2;i<=n;i++)
  {
    dp[i][0]=(dp[i-1][1]+dp[i-2][1])%mod;
    dp[i][1]=(dp[i-1][0]+dp[i-2][0])%mod;
  }
  return (dp[n][0]+dp[n][1])%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  cout<<solve(n)+solve(m)-2<<endl;
  return 0;
}