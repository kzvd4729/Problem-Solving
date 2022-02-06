/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/15/2020 15:25                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 483 ms                                          memory_used: 50800 KB                             
*  problem: https://codeforces.com/contest/1174/problem/F
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
//#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;
int ds[N+2],mx[N+2],sub[N+2],prnt[N+2];
vector<int>adj[N+2];
void dfs(int node,int par,int h)
{
  ds[node]=h;prnt[node]=par;
  for(auto x:adj[node])
  {
    if(x!=par)dfs(x,node,h+1);
  }
  mx[node]=ds[node];
  for(auto x:adj[node])
  {
    if(x!=par)mx[node]=max(mx[node],mx[x]);
  }
}
int vis[N+2],hg;
void dfs(int node,int par)
{
  sub[node]=1;
  for(auto x:adj[node])
  {
    if(x!=par&&vis[x]==0)
    {
      dfs(x,node);
      sub[node]+=sub[x];
    }
  }
}
int find(int node,int par)
{
  int mx=0,nd=-1;
  for(auto x:adj[node])
  {
    if(x!=par&&vis[x]==0)
    {
      if(sub[x]>mx)mx=sub[x],nd=x;
    }
  }
  if(nd==-1)return node;
  else return find(nd,node);
}
int solve(int node,int par)
{
  int nd=find(node,par);
  //cout<<nd<<endl;
  cout<<"d "<<nd<<endl;int x;cin>>x;
   if(x==0)cout<<"! "<<nd<<endl,exit(0);
  assert(x%2==0);
  while(x)
  {
    vis[nd]=1;x-=2;nd=prnt[nd];
  }
  return nd;
}
void go(int node,int par)
{
  if(ds[node]==hg)cout<<"! "<<node<<endl,exit(0);
  int mx=0,nd=-1,sz=0;
  for(auto x:adj[node])
  {
    if(x!=par&&vis[x]==0)
    {
      if(sub[x]>mx)mx=sub[x],nd=x;
      sz+=sub[x];
    }
  }
  if(mx>sz/2)
  {
    //cout<<node<<" "<<nd<<" "<<sz<<endl;
    nd=solve(nd,node);
    //cout<<"**"<<nd<<endl;
    go(nd,prnt[nd]);
  }
  else
  {
    cout<<"s "<<node<<endl;int nd;cin>>nd;
    go(nd,node);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,-1,0);
  //for(int i=1;i<=n;i++)cout<<mx[i]<<" ";cout<<endl;
  cout<<"d 1"<<endl;int x;cin>>x;
  for(int i=1;i<=n;i++)
  {
    if(ds[i]>x||mx[i]<x)vis[i]=1;
  }
  dfs(1,-1);
  //for(int i=1;i<=n;i++)cout<<sub[i]<<" ";cout<<endl;
  hg=x;go(1,-1);
   return 0;
}