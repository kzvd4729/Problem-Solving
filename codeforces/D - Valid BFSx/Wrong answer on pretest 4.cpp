/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2018 21:18                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1037/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,lev[N+2],vis[N+2];
vector<int>adj[N+2];
void dfs(int node,int par,int h)
{
  lev[node]=h;
  for(auto xx:adj[node])
  {
    if(xx==par)continue;
    dfs(xx,node,h+1);
  }
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
  dfs(1,-1,1);int now=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(vis[x])cout<<"NO"<<endl,exit(0);
    vis[x]=1;
    if(lev[x]>=now)now=lev[x];
    else cout<<"NO"<<endl,exit(0);
  }
  cout<<"YES"<<endl;
  return 0;
}