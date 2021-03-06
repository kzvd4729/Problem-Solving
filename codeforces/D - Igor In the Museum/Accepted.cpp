/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/19/2019 00:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 87500 KB                             
*  problem: https://codeforces.com/contest/598/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
string s[N+2];
int vis[N+2][N+2],n,m,ans[N*N+2];
void dfs(int ii,int jj,int id)
{
  vis[ii][jj]=id;int i,j;
  i=ii+1,j=jj;
  if(vis[i][j]==0&&s[i][j]=='.')dfs(i,j,id);
  i=ii-1,j=jj;
  if(vis[i][j]==0&&s[i][j]=='.')dfs(i,j,id);
  i=ii,j=jj+1;
  if(vis[i][j]==0&&s[i][j]=='.')dfs(i,j,id);
  i=ii,j=jj-1;
  if(vis[i][j]==0&&s[i][j]=='.')dfs(i,j,id);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int k;cin>>n>>m>>k;
  for(int i=0;i<n;i++)
    cin>>s[i];
  int cnt=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(s[i][j]=='*')continue;
      if(vis[i][j])continue;
      dfs(i,j,++cnt);
    }
  }
  for(int ii=0;ii<n;ii++)
  {
    for(int jj=0;jj<m;jj++)
    {
      if(s[ii][jj]=='.')continue;
      int i,j;
      i=ii+1,j=jj;
      if(i<n&&s[i][j]=='.')ans[vis[i][j]]++;
      i=ii-1,j=jj;
      if(i>=0&&s[i][j]=='.')ans[vis[i][j]]++;
      i=ii,j=jj+1;
      if(j<m&&s[i][j]=='.')ans[vis[i][j]]++;
      i=ii,j=jj-1;
      if(j>=0&&s[i][j]=='.')ans[vis[i][j]]++;
    }
  }
  while(k--)
  {
    int x,y;cin>>x>>y;
    cout<<ans[vis[x-1][y-1]]<<"\n";
  }
  return 0;
}