/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/20/2020 21:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/1370/problem/D
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
const int N=2e5;
int aa[N+2],k,dp[N+2],n;
bool ck(int md)
{
  memset(dp,0,sizeof dp);
  if(aa[1]<=md)dp[1]=1;
  for(int i=2;i<=n;i++)
  {
    dp[i]=dp[i-1];
    if(aa[i]<=md)dp[i]=max(dp[i],dp[i-2]+1);
  }
  if(k%2)
  {
    if(dp[n]>=(k+1)/2)return true;
  }
  else
  {
    if(dp[n-1]>=k/2)return true;
  }
  memset(dp,0,sizeof dp);
  dp[1]=0;
  for(int i=2;i<=n;i++)
  {
    dp[i]=dp[i-1];
    if(aa[i]<=md)dp[i]=max(dp[i],dp[i-2]+1);
  }
  if(k%2)
  {
    if(dp[n-1]>=k/2)return true;
  }
  else
  {
    if(dp[n]>=k/2)return true;
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
  int lo=1,hi=1e9,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ck(md))hi=md;else lo=md;
  }
  for(md=lo;md<=hi;md++)if(ck(md))cout<<md<<endl,exit(0);
  assert(0);
  return 0;
}