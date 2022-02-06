/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/17/2019 16:25                        
*  solution_verdict: Time limit exceeded on test 4           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 13700 KB                             
*  problem: https://codeforces.com/contest/1174/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int dep[N+2],sz[N+2],anc[N+2],leaf[N+2];
vector<int>adj[N+2],ex[N+2];
void extra(int node,int par)
{
  for(auto x:adj[node])
  {
    if(x==par)continue;
    extra(x,node);ex[node].push_back(x);
  }
}
void reckon(int node,int h)
{
  dep[node]=h;sz[node]=1;
  for(auto &x:adj[node])
  {
    reckon(x,h+1);sz[node]+=sz[x];
    if(sz[x]>=sz[adj[node][0]])
      swap(x,adj[node][0]);
  }
}
void dfs(int node)
{
  for(auto x:adj[node])
  {
    if(x==adj[node][0])anc[x]=anc[node];
    else anc[x]=x;dfs(x);
  }
}
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
  extra(1,-1);for(int i=1;i<=n;i++)adj[i]=ex[i];
  reckon(1,0);anc[1]=1;dfs(1);
  for(int i=1;i<=n;i++)
  {
    int x=anc[i];
    if(dep[i]>dep[leaf[x]])leaf[x]=i;
  }
  cout<<"d "<<1<<endl;int ds;cin>>ds;
  int node=1;
  while(true)
  {
    int lf=leaf[node];
    cout<<"d "<<lf<<endl;
    int x;cin>>x;int tar=0;
    for(int i=1;i<=n;i++)
    {
      if(anc[i]!=node)continue;
      if(dep[lf]-dep[i]==x&&dep[i]-dep[node]==ds)
        cout<<"! "<<i<<endl,exit(0);
      if(x-ds+dep[i]-dep[node]-(dep[lf]-dep[i])==0)
        if(dep[i]>dep[tar])tar=i;
    }
    ds-=(dep[tar]-dep[node]);ds--;
    cout<<"s "<<tar<<endl;cin>>node;
  }
  return 0;
}