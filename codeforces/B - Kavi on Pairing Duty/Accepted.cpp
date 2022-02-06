/****************************************************************************************
*  @author: kzvd4729#                                        created: May/27/2021 20:40                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 61 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1528/problem/B
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=998244353;
 int dd[N+2];
void cal()
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)dd[j]++;
  }
}
int dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cal();
  int n;cin>>n;
   dp[1]=1;int sm=1;
   for(int i=2;i<=n;i++)
  {
    dp[i]=(sm+dd[i])%mod;
    sm=(sm+dp[i])%mod;
  }
   cout<<dp[n]<<endl;
    return 0;
}