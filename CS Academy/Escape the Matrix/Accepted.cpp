/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 13 ms                                           memory_used: 1740 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m;
int dp[505][505],cnt;
char mat[505][505];
string s;
int dfs(int i,int j)
{
  if(dp[i][j])return dp[i][j];
  dp[i][j]=1;
  if(i>n||i<1||j>m||j<1)return 2;
  if(mat[i][j]=='D')dp[i][j]=dfs(i+1,j);
  if(mat[i][j]=='U')dp[i][j]=dfs(i-1,j);
  if(mat[i][j]=='L')dp[i][j]=dfs(i,j-1);
  if(mat[i][j]=='R')dp[i][j]=dfs(i,j+1);
  return dp[i][j];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>s;
    for(int j=1;j<=m;j++)
    {
      mat[i][j]=s[j-1];
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      dfs(i,j);
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(dp[i][j]==2)cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
}