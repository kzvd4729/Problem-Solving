/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-19 18:34:33                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 92 ms                                           memory_used: 2048 KB                              
*  problem: https://atcoder.jp/contests/abc143/tasks/abc143_e
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e2;
const long inf=1e18;
long ds[N+2][N+2],mt[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,l;cin>>n>>m>>l;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      ds[i][j]=inf,mt[i][j]=inf;
      if(i==j)ds[i][j]=0,mt[i][j]=0;
    }
  }
  while(m--)
  {
    int u,v,c;cin>>u>>v>>c;
    ds[u][v]=c;ds[v][u]=c;
  }
  for(int k=1;k<=n;k++)
  {
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        ds[i][j]=min(ds[i][j],ds[i][k]+ds[k][j]);
  }
  //cout<<"*"<<ds[3][1]<<endl;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      if(ds[i][j]<=l)mt[i][j]=1;
  }
  for(int k=1;k<=n;k++)
  {
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        mt[i][j]=min(mt[i][j],mt[i][k]+mt[k][j]);
  }
  int q;cin>>q;
  while(q--)
  {
    int u,v;cin>>u>>v;
    if(mt[u][v]==inf)cout<<-1<<"\n";
    else cout<<mt[u][v]-1<<"\n";
  }
  return 0;
}