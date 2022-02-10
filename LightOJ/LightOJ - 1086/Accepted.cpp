/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-02 23:46:46                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 28                                         memory_used (MB): 2.3                             
*  problem: https://vjudge.net/problem/LightOJ-1086
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=15;
long mt[N+2][N+2],dp[(1<<15)+2];int n,dg[N+2];
vector<int>vec;
long dfs(int msk,int id)
{
  if(id>=n)return 0;
  if((msk&(1<<id)))return dfs(msk,id+1);
  if(dp[msk]!=-1)return dp[msk];
  long now=1e15;
  for(int i=id+1;i<n;i++)
  {
    if((msk&(1<<i)))continue;
    now=min(now,mt[vec[id]][vec[i]]+dfs(((msk|(1<<id))|(1<<i)),id+1));
  }
  return dp[msk]=now;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("out.txt","w",stdout);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int m;cin>>n>>m;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        mt[i][j]=1e15;
    long sm=0;
    memset(dg,0,sizeof(dg));
    for(int i=1;i<=m;i++)
    {
      int u,v,w;cin>>u>>v>>w;dg[u]++;dg[v]++;
      mt[u][v]=min(mt[u][v],w*1LL);
      mt[v][u]=min(mt[v][u],w*1LL);
      sm+=w;
    }
    for(int k=1;k<=n;k++)
      for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          mt[i][j]=min(mt[i][j],mt[i][k]+mt[k][j]);
    vec.clear();
    for(int i=1;i<=n;i++)
      if(dg[i]%2)
        vec.push_back(i);
    n=vec.size();
    memset(dp,-1,sizeof(dp));
    cout<<"Case "<<++tc<<": "<<sm+dfs(0,0)<<"\n";
  }
  return 0;
}