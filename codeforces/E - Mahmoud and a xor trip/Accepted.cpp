/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/20/2018 23:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 545 ms                                          memory_used: 8700 KB                              
*  problem: https://codeforces.com/contest/766/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,ar[N+2],sz[N+2],tot,mark[N+2];
int zr[22],on[22];
long ans;
vector<int>adj[N+2];
void dfs(int node,int par)
{
  tot++;sz[node]=1;
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    dfs(x,node);sz[node]+=sz[x];
  }
}
int find_center(int node,int par)
{
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    if(sz[x]>tot/2)return find_center(x,node);
  }
  return node;
}
void cal(int node,int par,int xr)
{
  for(int i=20;i>=0;i--)
  {
    if(xr&(1<<i))ans+=((zr[i]*1LL)*(1<<i));
    else ans+=((on[i]*1LL)*(1<<i));
  }
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    cal(x,node,xr^ar[x]);
  }
}
void add(int node,int par,int xr)
{
  for(int i=20;i>=0;i--)
  {
    if(xr&(1<<i))on[i]++;
    else zr[i]++;
  }
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    add(x,node,xr^ar[x]);
  }
}
void centroid(int node,int par)
{
  tot=0;dfs(node,-1);
  int center=find_center(node,-1);
  mark[center]=1;
  for(int i=20;i>=0;i--)
  {
    if(ar[center]&(1<<i))on[i]++;
    else zr[i]++;
  }
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    cal(x,-1,ar[x]);
    add(x,-1,ar[center]^ar[x]);
  }
  memset(on,0,sizeof(on));
  memset(zr,0,sizeof(zr));
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    centroid(x,center);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;for(int i=1;i<=n;i++)cin>>ar[i],ans+=ar[i];
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  centroid(1,-1);cout<<ans<<endl;
  return 0;
}