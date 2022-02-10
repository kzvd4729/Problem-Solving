/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-15 19:33:06                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1559                                       memory_used (MB): 3.3                             
*  problem: https://vjudge.net/problem/LightOJ-1180
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int xx[N+2],yy[N+2],n,m,md,f;
bool vis[N+2][N+2][N+2];
void dfs(int i,int m1,int m2)
{
  if(m1<0)m1=0;if(m2<0)m2=0;
  if(!m1&&!m2)
  {
    f=1;return ;
  }
  if(i>n)return ;
  if(vis[i][m1][m2])return ;
  vis[i][m1][m2]=1;

  for(int l=0; ;l++)
  {
    if(xx[i]*l>md)break;
    dfs(i+1,m1-l,m2-(md-l*xx[i])/yy[i]);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      cin>>xx[i]>>yy[i];
    int lo=1,hi=50000;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
          for(int k=0;k<=m;k++)
            vis[i][j][k]=0;
      f=0;dfs(1,m,m);
      if(f)hi=md;else lo=md;
    }
    for(md=lo;md<=hi;md++)
    {
      for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
          for(int k=0;k<=m;k++)
            vis[i][j][k]=0;
      f=0;dfs(1,m,m);
      if(f)break;
    }
    cout<<"Case "<<++tc<<": "<<md<<"\n";
  }
  return 0;
}