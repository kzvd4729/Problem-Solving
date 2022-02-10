/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-08 13:09:31                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-taste-of-win
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long 
using namespace std;
const int N=1e7;
const int mod=1e9+7;
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int dp[N+2][2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int n,m;cin>>n>>m;int p=m;
  m=big(2,m)-1;

  if(p<=28&&m<n)cout<<0<<endl,exit(0);

  dp[1][1]=m;dp[2][1]=(1LL*m*(m-1))%mod;

  for(int i=3;i<=n;i++)
  {
    dp[i][0]=dp[i-1][1];
    dp[i][1]=((1LL*dp[i-1][0]*(m-i+1))%mod+(1LL*dp[i-1][1]*(m-i))%mod)%mod;
  }
  cout<<(dp[n][1]+mod)%mod;
  return 0;
}