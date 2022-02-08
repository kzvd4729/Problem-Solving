/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-05-02 18:06:01                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 20 ms                                           memory_used: 5120 KB                              
*  problem: https://atcoder.jp/contests/agc024/tasks/agc024_b
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
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int aa[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  int mx=0;
  for(int i=n;i>=1;i--)
  {
    dp[aa[i]]=dp[aa[i]+1]+1;
    mx=max(mx,dp[aa[i]]);
  }
  cout<<n-mx<<endl;
  return 0; 
}