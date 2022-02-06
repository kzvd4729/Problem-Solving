/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/06/2019 19:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2401 ms                                         memory_used: 105800 KB                            
*  problem: https://codeforces.com/contest/1009/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int sz[N+2],hgh[N+2],mxm=-1,dp,fr[N+2];
int ans[N+2];
vector<int>adj[N+2];
void reckon(int node,int par,int hg)
{
  sz[node]=1;hgh[node]=hg;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    reckon(x,node,hg+1);sz[node]+=sz[x];
  }
}
void add(int node,int par)
{
  int x=++fr[hgh[node]];
  if(x>mxm)mxm=x,dp=hgh[node];
  //cout<<"*"<<dp<<endl;
  if(x==mxm)dp=min(dp,hgh[node]);
   for(auto x:adj[node])
  {
    if(x==par)continue;
    add(x,node);
  }
}
void _clear(int node,int par)
{
  --fr[hgh[node]];
  for(auto x:adj[node])
  {
    if(x==par)continue;
    _clear(x,node);
  }
}
void dfs(int node,int par,int cl)
{
  int mx=-1,big;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(sz[x]>mx)mx=sz[x],big=x;
  }
  for(auto x:adj[node])
  {
    if(x==par||x==big)continue;
    dfs(x,node,1);
  }
  if(mx!=-1)dfs(big,node,0);
   for(auto x:adj[node])
  {
    if(x==par||x==big)continue;
    add(x,node);
  }
  int x=++fr[hgh[node]];
  if(x>mxm)mxm=x,dp=hgh[node];
  if(x==mxm)dp=min(dp,hgh[node]);
   if(cl)_clear(node,par),mxm=-1;
  ans[node]=dp-hgh[node];
  //ans[node]=mxm;
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
  reckon(1,-1,0);dfs(1,-1,0);
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}