/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/17/2019 14:43                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1174/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int dep[N+2],sz[N+2];
void reckon(int node,int par,int h)
{
  dep[node]=h;sz[node]=1;
  for(auto &x:adj[node])
  {
    if(x==par)continue;
    reckon(x,node,h+1);sz[node]+=sz[x];
    if(sz[x]>=sz[adj[node][0]])
      swap(x,adj[node][0]);
  }
}
void dfs(int node,int par)
{
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(x==adj[node][0])anc[x]=anc[node];
    else anc[x]=x;dfs(x,node);
  }
}
dont compile
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  reckon(1,-1,0);anc[1]=1;dfs(1,-1);
    return 0;
}