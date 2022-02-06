/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/15/2018 16:08                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/343/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int n,sz[N+2],in[N+2],out[N+2],tim;
int lin[N+2],anc[N+2];
vector<int>adj[N+2];
void reckon(int node,int par)
{
  sz[node]=1;
  for(auto &x:adj[node])
  {
    if(x==par)continue;
    reckon(x,node);sz[node]+=sz[x];
    if(sz[x]>=sz[adj[node][0]])swap(x,adj[node][0]);
  }
}
void hld(int node,int par)
{
  in[node]=++tim;lin[tim]=node;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(x==adj[node][0])anc[x]=anc[node];
    else anc[x]=x;hld(x,node);
  }
  out[node]=tim;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++)anc[i]=i;
  reckon(1,-1);hld(1,-1);
  for(int i=1;i<=n;i++)
    cout<<anc[i]<<" ";
  cout<<endl;
  return 0;
}