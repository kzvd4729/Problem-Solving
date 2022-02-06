/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2020 19:32                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 12900 KB                             
*  problem: https://codeforces.com/contest/835/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
vector<pair<int,int> >adj[N+2],tree[N+2];//rooted tree
int u,v,part[N+2],cn;
int vis[N+2],lev[N+2];
int root,vs[N+2];
void dfs(int node,int par)
{
  if(vs[node]){root=node;return ;}
  vs[node]=1;
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    dfs(x.first,node);
  }
}
void dfs(int node,int par,int lv)
{
  vis[node]=1,lev[node]=lv;part[node]=par;
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    if(vis[x.first])u=node,v=x.first,cn=x.second;
    else
    {
      //cout<<node<<" --> "<<x.first<<" "<<x.second<<endl;
      tree[node].push_back(x);
      dfs(x.first,node,lv+1);
    }
  }
}
long dp[N+2],ans,ds[N+2];
long dds(int node,long ad)
{
  //cout<<"hrere"<<endl;
  ds[node]=ad;
  for(auto x:tree[node])
  {
    long now=dds(x.first,ad+x.second)+x.second;
    ans=max(ans,now+dp[node]);
    dp[node]=max(dp[node],now);
  }
  ans=max(ans,dp[node]);
  //cout<<dp[node]<<endl;
  return dp[node];
}
bool path[N+2];
bool find(int node)
{
  //cout<<node<<" "<<v<<endl;
  if(node==v)return path[node]=true;
  for(auto x:tree[node])
  {
    path[node]|=find(x.first);
  }
  return path[node];
}
long mx,dw;long up[N+2];
void rec(int node,long prv)
{
  up[node]=max(prv,ds[node]);
  for(auto x:tree[node])
  {
    if(!path[x.first])up[node]=max(up[node],dp[x.first]+ds[x.first]);
  }
  for(auto x:tree[node])
  {
    if(path[x.first])rec(x.first,up[node]);
  }
}
void ck(int v,int u,int V)
{
  if(u==v)cout<<ans<<endl,exit(0);
  long now=dw+dp[V];
  now=max(now,up[part[v]]+cn+max(dp[V],dw));
  //cout<<v<<" "<<now<<" "<<dw<<" "<<up[part[v]]<<endl;
  ans=min(ans,now);
   for(auto x:tree[part[v]])
  {
    if(!path[x.first])dw=max(dw,dp[x.first]+x.second+ds[V]-ds[part[v]]);
  }
  dw=max(dw,ds[V]-ds[part[v]]);
  ck(part[v],u,V);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  dfs(1,0);//cout<<root<<endl;
  dfs(root,0,0);if(lev[u]>lev[v])assert(0);
  //cout<<root<<endl;
  dds(root,0);//cout<<dp[root]<<endl;
  //cout<<v<<endl;
  for(auto x:tree[root])
    if(!find(x.first))mx=max(mx,dp[x.first]+x.second);
  //cout<<ans<<endl;
  rec(root,0LL);
  //for(int i=1;i<=n;i++)cout<<up[i]<<" ";
    //cout<<endl;
  ck(v,u,v);
   return 0;
}