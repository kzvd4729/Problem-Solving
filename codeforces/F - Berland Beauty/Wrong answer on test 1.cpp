/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/04/2020 22:14                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 98000 KB                             
*  problem: https://codeforces.com/contest/1296/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3,inf=1e9;
vector<int>adj[N+2];
int lv[N+2],prnt[N+2],ed[N+2][N+2],ans[N+2];
void dfs(int node,int par,int l)
{
  lv[node]=l,prnt[node]=par;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,l+1);
  }
}
bool lca(int u,int v,int vl)
{
  if(lv[u]<lv[v])swap(u,v);int f=0;
  while(lv[u]>lv[v])
  {
    int e=ed[u][prnt[u]];u=prnt[u];if(!e)assert(0);
    if(ans[e]==-1)ans[e]=vl,f=1;
    //cout<<"here"<<endl;
  }
  while(u!=v)
  {
    int e=ed[u][prnt[u]];u=prnt[u];if(!e)assert(0);
    if(ans[e]==-1)ans[e]=vl,f=1;
     e=ed[v][prnt[v]];v=prnt[v];if(!e)assert(0);
    if(ans[e]==-1)ans[e]=vl,f=1;
  }
  return f;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    ed[u][v]=1;ed[v][u]=i;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,-1,0);
  for(int i=1;i<=n;i++)ans[i]=-1;
   int m;cin>>m;vector<vector<int> >v(m);
  for(int i=0;i<m;i++)
  {
    v[i].resize(3);
    cin>>v[i][1]>>v[i][2]>>v[i][0];
  }
  sort(v.begin(),v.end());reverse(v.begin(),v.end());
  for(auto x:v)
  {
    if(!lca(x[1],x[2],x[0]))cout<<-1<<endl,exit(0);
  }
  for(int i=1;i<=n;i++)if(ans[i]==-1)ans[i]=1e6;
  for(int i=1;i<n;i++)cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}