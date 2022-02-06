/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/03/2018 21:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 33200 KB                             
*  problem: https://codeforces.com/contest/540/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2,r=0,s=1,p=2;
double dp[N+2][N+2][N+2][4];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
      dp[i][j][0][r]=1.0;
  for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
      dp[0][i][j][s]=1.0;
  for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
      dp[i][0][j][p]=1.0;
  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=N;j++)
    {
      for(int k=1;k<=N;k++)
      {
        double ij=i*j,jk=j*k,ki=k*i;
        double tt=ij+jk+ki;ij/=tt,jk/=tt,ki/=tt;
        dp[i][j][k][r]=ij*dp[i][j-1][k][r]+jk*dp[i][j][k-1][r]+ki*dp[i-1][j][k][r];
        dp[i][j][k][s]=ij*dp[i][j-1][k][s]+jk*dp[i][j][k-1][s]+ki*dp[i-1][j][k][s];
        dp[i][j][k][p]=ij*dp[i][j-1][k][p]+jk*dp[i][j][k-1][p]+ki*dp[i-1][j][k][p];
      }
    }
  }
  int a,b,c;cin>>a>>b>>c;
  cout<<setprecision(10)<<fixed;
  cout<<dp[a][b][c][r]<<" "<<dp[a][b][c][s]<<" "<<dp[a][b][c][p]<<endl;
  return 0;
}