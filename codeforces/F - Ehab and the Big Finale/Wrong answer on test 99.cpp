/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/17/2019 12:54                        
*  solution_verdict: Wrong answer on test 99                 language: GNU C++14                               
*  run_time: 436 ms                                          memory_used: 18900 KB                             
*  problem: https://codeforces.com/contest/1174/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int mx[N+2];
vector<int>adj[N+2];
void dfs(int node,int par)
{
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);
    mx[node]=max(mx[node],mx[x]+1);
  }
}
void walk(int node,int par,int ds)
{
  if(!ds)cout<<"! "<<node<<endl,exit(0);
  int cnt=0,tar;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(mx[x]>=ds-1)cnt++,tar=x;
  }
  if(cnt==1)walk(tar,node,ds-1);
  cout<<"s "<<node<<endl;cin>>tar;
  walk(tar,node,ds-1);
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
  dfs(1,-1);
  cout<<"d "<<1<<endl;
  int x;cin>>x;walk(1,-1,x);
  return 0;
}