/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/14/2019 17:55                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 31500 KB                             
*  problem: https://codeforces.com/contest/1276/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int vis[N+2],cnt,par[N+2],aa[2][N+2],sz[N+2];
vector<int>adj[N+2];
void dfs(int node,int i)
{
  ++cnt,vis[node]=1,par[node]=i;
  for(auto x:adj[node])
    if(!vis[x])dfs(x,i);
}
void dfs2(int node,int i)
{
  aa[i][par[node]]=1,vis[node]=1;
  for(auto x:adj[node])
    if(!vis[x])dfs2(x,i);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,a,b;cin>>n>>m>>a>>b;
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;
      if((u==a&&v==b)||(u==b&&v==a))continue;
      if(u==a)adj[a].push_back(v);
      else if(v==a)adj[a].push_back(u);
       else if(u==b)adj[b].push_back(v);
      else if(v==b)adj[b].push_back(u);
       else 
      {
        adj[u].push_back(v);adj[v].push_back(u);
      }
    }
    for(int i=1;i<=n;i++)
    {
      vis[i]=0,par[i]=0,aa[1][i]=0,aa[2][i]=0,sz[i]=0;
    }
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
      if(vis[i]||i==a||i==b)continue;
      cnt=0;dfs(i,i);sz[i]=cnt;
      v.push_back(i);
      //cout<<i<<" --> "<<cnt<<endl;
    }
    //cout<<sz[3]<<" ** "<<sz[4]<<endl;
    for(int i=1;i<=n;i++)vis[i]=0;
    //vis[b]=1;
    for(auto x:adj[a])dfs2(x,1);
    for(int i=1;i<=n;i++)vis[i]=0;
    //vis[a]=1;
    for(auto x:adj[b])dfs2(x,2);
     //cout<<aa[1][3]<<" "<<aa[2][3]<<" "<<aa[1][4]<<" "<<aa[2][4]<<endl;
     int sza=0,szb=0;
    for(auto x:v)
    {
      if(aa[1][x]&&(!aa[2][x]))sza+=sz[x];
      if(!(aa[1][x])&&aa[2][x])szb+=sz[x];
    }
     cout<<(1LL*sza*szb)<<"\n";
  }
  return 0;
}