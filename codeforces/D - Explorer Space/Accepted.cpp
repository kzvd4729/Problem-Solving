/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/23/2021 21:54                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 171 ms                                          memory_used: 13800 KB                             
*  problem: https://codeforces.com/contest/1517/problem/D
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
const int N=500,inf=1e9,mod=1e9+7;
 int a[N+2][N+2],b[N+2][N+2];
int dp[N+2][N+2][10+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m,k;cin>>n>>m>>k;
   for(int i=1;i<=n;i++)
  {
    for(int j=1;j<m;j++)cin>>a[i][j];
  }
   for(int i=1;i<n;i++)
  {
    for(int j=1;j<=m;j++)cin>>b[i][j];
  }
   int d=k/2;
   for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      for(int l=1;l<=d;l++)dp[i][j][l]=inf;
    }
  }
   for(int l=1;l<=d;l++)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(j+1<=m)dp[i][j][l]=min(dp[i][j][l],a[i][j]+dp[i][j+1][l-1]);
        if(j-1>=1)dp[i][j][l]=min(dp[i][j][l],a[i][j-1]+dp[i][j-1][l-1]);
         if(i+1<=n)dp[i][j][l]=min(dp[i][j][l],b[i][j]+dp[i+1][j][l-1]);
        if(i-1>=1)dp[i][j][l]=min(dp[i][j][l],b[i-1][j]+dp[i-1][j][l-1]);
      }
    }
  }
   if(k%2)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)cout<<-1<<" ";
        cout<<endl;
    }
    exit(0);
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)cout<<2*dp[i][j][d]<<" ";
      cout<<endl;
  }
    return 0;
}