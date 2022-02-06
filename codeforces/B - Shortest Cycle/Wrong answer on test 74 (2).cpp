/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/20/2020 10:56                        
*  solution_verdict: Wrong answer on test 74                 language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 53900 KB                             
*  problem: https://codeforces.com/contest/1205/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long aa[N+2];
vector<int>adj[N+2],tree[N+2];//rooted tree
vector<int>bkadj[N+2];//edges doesn't belong to the tree(end nodes are in a chain)
int vis[N+2],lev[N+2];
void dfs(int node,int par,int lv)
{
  vis[node]=1,lev[node]=lv;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(vis[x])
    {
      bkadj[node].push_back(x);bkadj[x].push_back(node);
    }
    else
    {
      tree[node].push_back(x);tree[x].push_back(node);
      dfs(x,node,lv+1);
    }
  }
}
int cy=1e9;
void dds(int node,int par)
{
  for(auto x:bkadj[node])cy=min(cy,abs(lev[node]-lev[x])+1);
  for(auto x:tree[node])
  {
    if(x==par)continue;
    dds(x,node);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int m=0;
  for(int i=1;i<=n;i++)
  {
    long x;cin>>x;if(x==0LL)continue;
    aa[++m]=x;
  }
  n=m;
  if(n>1000)cout<<3<<endl,exit(0);
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<i;j++)
    {
      if((aa[i]&aa[j])==0LL)continue;
      adj[i].push_back(j);
      adj[j].push_back(i);
      //cout<<i<<" "<<j<<endl;
    }
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    dfs(i,-1,0);dds(i,-1);
  }
  assert(cy>2);
  if(cy==1e9)cy=-1;cout<<cy<<endl,exit(0);
  return 0;
}