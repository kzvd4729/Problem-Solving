/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2019 12:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1325 ms                                         memory_used: 51200 KB                             
*  problem: https://codeforces.com/contest/732/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
int vis[N+2],level[N+2],sz,ex[N+2],stst[N+2],brd[N+2];
vector<int>ok;
vector<pair<int,int> >adj[N+2],edge;
void dfs(int node,int par,int lv)
{
  vis[node]=1;level[node]=lv;
  for(auto z:adj[node])
  {
    int x=z.first;if(x==par)continue;
    if(vis[x])ex[abs(z.second)]=1;
    else dfs(x,node,lv+1);
  }
}
int bridges(int node,int par,int nm)
{
  int mn=1e9;
  for(auto z:adj[node])
  {
    int x=z.first;
    if(x==par||ex[abs(z.second)])continue;
    mn=min(mn,bridges(x,node,abs(z.second)));
  }
  for(auto z:adj[node])
  {
    if(!ex[abs(z.second)])continue;
    mn=min(mn,level[z.first]);
  }
  if(mn>=level[node]&&par!=-1)brd[nm]=1;
  return mn;
}
void visit(int node)
{
  sz++;vis[node]=1;
  for(auto z:adj[node])
  {
    int x=z.first;if(vis[x])continue;
    if(brd[abs(z.second)])continue;
    visit(x);
  }
}
void mxcmp(int node,int nm)
{
  vis[nm]=1;
  for(auto z:adj[node])
  {
    int x=z.first;
    if(brd[abs(z.second)]){ok.push_back(node);continue;}
    if(vis[abs(z.second)])continue;
    if(z.second<0)stst[abs(z.second)]=1;
    mxcmp(x,abs(z.second));
  }
}
void mncmp(int node,int nm)
{
  vis[nm]=1;
  for(auto z:adj[node])
  {
    int x=z.first;
    if(vis[abs(z.second)])continue;
    if(z.second>0)stst[abs(z.second)]=1;
    mncmp(x,abs(z.second));
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back({v,i});
    adj[v].push_back({u,-i});
    edge.push_back({u,v});
  }
  dfs(1,-1,0);bridges(1,-1,0);
  int mxsz=0,rt;
  memset(vis,0,sizeof(vis));
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;sz=0;
    visit(i);if(sz>mxsz)mxsz=sz,rt=i;
  }
  memset(vis,0,sizeof(vis));
  mxcmp(rt,0);
  for(auto x:ok)mncmp(x,0);
  cout<<mxsz<<"\n";
  for(int i=0;i<edge.size();i++)
  {
    if(stst[i+1])cout<<edge[i].second<<" "<<edge[i].first<<"\n";
    else cout<<edge[i].first<<" "<<edge[i].second<<"\n";
  }
  return 0;
}