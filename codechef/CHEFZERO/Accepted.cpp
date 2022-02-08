/****************************************************************************************
*  @author: kzvd4729                                         created: 16-09-2018 23:20:50                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.13 sec                                        memory_used: 111M                                 
*  problem: https://www.codechef.com/SEPT18A/problems/CHEFZERO
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int mat[N+2][N+2],ans[N+2][N+2];
int sum,avg,ex,vis[N+2][N+2],sm,kk=1,k,n,m;
void dfs(int r,int c)
{
  sm+=mat[r][c];ans[r][c]=kk;vis[r][c]=1;
  //cout<<sm<<"__________"<<endl;
  if(ex<0&&sm>=avg+ex&&kk<k)
  {
    ex+=(avg-sm);
    kk++,sm=0;
  }
  else if(sm>=avg&&kk<k)
  {
    ex+=(avg-sm);
    kk++,sm=0;
  }
  if(r+1<=n&&!vis[r+1][c])dfs(r+1,c);
  if(r-1>=1&&!vis[r-1][c])dfs(r-1,c);
  if(c+1<=m&&!vis[r][c+1])dfs(r,c+1);
  if(c-1>=1&&!vis[r][c-1])dfs(r,c-1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>mat[i][j];sum+=mat[i][j];
    }
  }
  avg=sum/k;ex=sum-avg*k;
  dfs(1,1);
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}