/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/01/2020 14:54                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 105200 KB                            
*  problem: https://codeforces.com/contest/1433/problem/F
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
const int N=70;
int a[N+2][N+2],d[N+2][N+2][N+2][N+2],n,m,k,dp[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
   for(int i=0;i<N+2;i++)
  {
    for(int j=0;j<N+2;j++)
      for(int k=0;k<N+2;k++)
        for(int l=0;l<N+2;l++)d[i][j][k][l]=-1e9;
  }
   for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)cin>>a[i][j];
     for(int j=0;j<=m;j++)for(int t=0;t<=m/2;t++)d[i][j][t][0]=0;
    for(int j=1;j<=m;j++)
    {
      for(int t=1;t<=m/2;t++)
      {
        for(int md=0;md<k;md++)
        {
          d[i][j][t][md]=max(d[i][j][t-1][md],d[i][j-1][t][md]);
          d[i][j][t][md]=max(d[i][j][t][md],d[i][j-1][t-1][(md-a[i][j]+k*k*k)%k]+a[i][j]);
        }
      }
    }
  }
  /*for(int i=1;i<=n;i++)
  {
    for(int j=0;j<k;j++)
      cout<<d[i][m][m/2][j]<<" ";
    cout<<endl;
  }*/
  for(int i=0;i<N+2;i++)for(int j=0;j<N+2;j++)dp[i][j]=-1e9;
  dp[0][0]=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<k;j++)
    {
      for(int l=0;l<k;l++)
      {
        dp[i][j]=max(dp[i][j],dp[i-1][(j-l+k*k*k)%k]+d[i][m][m/2][l]);
      }
    }
  }
  cout<<dp[n][0]<<endl;
  return 0;
}