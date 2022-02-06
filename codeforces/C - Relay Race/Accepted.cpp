/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/26/2020 19:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 904 ms                                          memory_used: 216000 KB                            
*  problem: https://codeforces.com/contest/213/problem/C
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
const int N=3e2,mod=1e9+7;
int a[N+2][N+2],n,dp[N+2][N+2][N+2][2];
int dfs(int i,int j,int k,int f)
{
  if(i==n&&j==n&&k==n)return 0;
  if(dp[i][j][k][f]!=mod)return dp[i][j][k][f];
  int ret=-mod;
  if(j==k&&k<n)ret=max(ret,a[i][k+1]+dfs(i,j+1,k+1,1));
  if(i<n)
  {
    if(j<k)ret=max(ret,a[i+1][j]+a[i+1][k]+dfs(i+1,j,k,0));
    else ret=max(ret,a[i+1][j]+dfs(i+1,j,k,0));
  }
  if(f==0)
  {
    if(j<k-1)ret=max(ret,a[i][j+1]+dfs(i,j+1,k,0));
    else if(j<k)ret=max(ret,dfs(i,j+1,k,0));
  }
  if(k<n)ret=max(ret,a[i][k+1]+dfs(i,j,k+1,1));
  return dp[i][j][k][f]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)cin>>a[i][j];
  }
  if(n==1)cout<<a[1][1]<<endl,exit(0);
  for(int i=0;i<N+2;i++)
  {
    for(int j=0;j<N+2;j++)
      for(int k=0;k<N+2;k++)dp[i][j][k][0]=mod,dp[i][j][k][1]=mod;
  }
  cout<<a[1][1]+dfs(1,1,1,0)<<endl;
  return 0;
}