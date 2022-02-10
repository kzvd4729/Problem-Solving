/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-12-18 15:57:54                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 90                                         memory_used (MB): 10.6                            
*  problem: https://vjudge.net/problem/LightOJ-1071
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int mat[N+2][N+2],n,m,dp[N+2][N+2][N+2][2];
int dfs(int st,int r1,int r2,int f)
{
  if(st>n)
  {
    if(r1==m-1&&r2==m)return 0;
    else return -1e9;
  }
  if(dp[st][r1][r2][f]!=-1)return dp[st][r1][r2][f];
  int now=0;
  if(!f)
  {
    now=max(now,dfs(st,r1,r2,1));
    if(r1+1<r2)now=max(now,mat[st][r1]+dfs(st,r1+1,r2,0));
  }
  else
  {
    now=max(now,mat[st][r1]+mat[st][r2]+dfs(st+1,r1,r2,0));
    if(r2<m)now=max(now,mat[st][r2]+dfs(st,r1,r2+1,1));
  }
  return dp[st][r1][r2][f]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        cin>>mat[i][j];
    memset(dp,-1,sizeof(dp));
    cout<<"Case "<<++tc<<": "<<dfs(1,1,2,0)<<endl;
  }
  return 0;
}