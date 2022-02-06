/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/24/2018 00:42                        
*  solution_verdict: Time limit exceeded on test 19          language: GNU C++17                               
*  run_time: 1500 ms                                         memory_used: 9000 KB                              
*  problem: https://codeforces.com/contest/677/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e2;
int mat[N+2][N+2],n,m,p,dp[N+2][N+2];
vector<pair<int,int> >pos[N*N+2];
int dfs(int r,int c,int tr)
{
  if(tr>p)return 0;
  if(dp[r][c]!=-1)return dp[r][c];
  int here=1e9;
  for(auto x:pos[tr])
    here=min(here,abs(r-x.first)+abs(c-x.second)+dfs(x.first,x.second,tr+1));
  return dp[r][c]=here;
 }
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>p;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>mat[i][j];
      pos[mat[i][j]].push_back({i,j});
    }
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,1,1)<<endl;
  return 0;
}