/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/15/2020 20:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 404 ms                                          memory_used: 98600 KB                             
*  problem: https://codeforces.com/contest/1446/problem/B
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
const int N=5000;
int n,m;string a,b;
int dp[N+2][N+2];
int dfs(int i,int j)
{
  if(i==n||j==m)return 0;
  if(dp[i][j]!=-1)return dp[i][j];
  int ret=0;
  ret=max(ret,-1+dfs(i+1,j));
  ret=max(ret,-1+dfs(i,j+1));
  if(a[i]==b[j])ret=max(ret,2+dfs(i+1,j+1));
  return dp[i][j]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>a>>b;
  int ret=0;memset(dp,-1,sizeof dp);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
      ret=max(ret,dfs(i,j));
  }
  cout<<ret<<endl;
  return 0;
}