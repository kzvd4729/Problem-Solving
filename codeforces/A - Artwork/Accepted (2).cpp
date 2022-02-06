/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/04/2019 23:38                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 46 ms                                           memory_used: 4400 KB                              
*  problem: https://codeforces.com/gym/102346/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int aa[N+2],bb[N+2],cc[N+2],br[5][N+2],vis[N+2];
vector<int>adj[N+2];
int dis(int i,int j)
{
  return (aa[i]-aa[j])*(aa[i]-aa[j])+(bb[i]-bb[j])*(bb[i]-bb[j]);
}
void ya()
{
  cout<<"N"<<endl,exit(0);
}
void dfs1(int node)
{
  if(vis[node])return ;
  if(br[4][node]||br[3][node])ya();
  vis[node]=1;
   for(auto x:adj[node])
    dfs1(x);
}
void dfs2(int node)
{
  if(vis[node])return ;
  if(br[4][node]||br[3][node])ya();
  vis[node]=1;
   for(auto x:adj[node])
    dfs2(x);
}
void dfs3(int node)
{
  if(vis[node])return ;
  if(br[1][node]||br[2][node])ya();
  vis[node]=1;
   for(auto x:adj[node])
    dfs3(x);
}
void dfs4(int node)
{
  if(vis[node])return ;
  if(br[1][node]||br[2][node])ya();
  vis[node]=1;
   for(auto x:adj[node])
    dfs4(x);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=k;i++)adj[i].clear();
  memset(br,0,sizeof(br));
  for(int i=1;i<=k;i++)
    cin>>aa[i]>>bb[i]>>cc[i];
   for(int i=1;i<=k;i++)
  {
    for(int j=1;j<=k;j++)
    {
      if(dis(i,j)<=(cc[i]+cc[j])*(cc[i]+cc[j]))
        adj[i].push_back(j);
    }
  }
  for(int i=1;i<=k;i++)
  {
    if(aa[i]<=cc[i])br[1][i]=1;
    if(n-aa[i]<=cc[i])br[3][i]=1;
     if(bb[i]<=cc[i])br[4][i]=1;
    if(m-bb[i]<=cc[i])br[2][i]=1;
  }
  for(int i=1;i<=k;i++)
  {
    if(br[1][i])
    {
      memset(vis,0,sizeof(vis));
      dfs1(i);
    }
  }
   for(int i=1;i<=k;i++)
  {
    if(br[2][i])
    {
      memset(vis,0,sizeof(vis));
      dfs2(i);
    }
  }
   for(int i=1;i<=k;i++)
  {
    if(br[3][i])
    {
      memset(vis,0,sizeof(vis));
      dfs3(i);
    }
  }
   for(int i=1;i<=k;i++)
  {
    if(br[4][i])
    {
      memset(vis,0,sizeof(vis));
      dfs4(i);
    }
  }
  cout<<"S"<<endl;
   return 0;
}