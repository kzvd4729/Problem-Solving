/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/06/2020 19:45                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4000 KB                              
*  problem: https://codeforces.com/contest/1000/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
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
#include<random>
#define long long long
using namespace std;
const int N=1e3,mod=998244353;
int n,a[N+2],dp[N+2][N+2];
int dfs(int i,int r)
{
  if(i>n)return r==0;
  if(dp[i][r]!=-1)return dp[i][r];
  int ret=0;
  if(r)
  {
    ret=(ret+dfs(i+1,r))%mod;
    ret=(ret+dfs(i+1,r-1))%mod;
  }
  else
  {
    ret=(ret+dfs(i+1,r))%mod;
    if(a[i]<=n)ret=(ret+dfs(i+1,a[i]))%mod;
  }
  return dp[i][r]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;for(int i=1;i<=n;i++)cin>>a[i];
   memset(dp,-1,sizeof dp);
  cout<<(dfs(1,0)-1+mod)%mod<<endl;
    return 0;
}