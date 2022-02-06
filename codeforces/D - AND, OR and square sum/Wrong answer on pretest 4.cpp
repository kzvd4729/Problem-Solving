/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/18/2020 22:21                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1368/problem/D
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
int aa[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   dp[n+1]=(1<<22)-1;
  for(int i=n;i>=1;i--)dp[i]=(dp[i+1]&aa[i]);
   long ans=0;int ad=0;
  for(int i=1;i<=n;i++)
  {
    aa[i]|=ad;
    int now=((dp[i+1]|ad)&aa[i]);
    ans+=(1LL*now*now);ad|=aa[i];
  }
  cout<<ans<<endl;
  return 0;
}