/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2018 19:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/14/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2;
int mx,nd,vis[N+2];
vector<int>adj[N+2];
vector<pair<int,int> >ed;
void dfs(int node,int ds)
{
  vis[node]=1;
  if(ds>mx)mx=ds,nd=node;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    dfs(x,ds+1);
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
    ed.push_back({u,v});
  }
  long ans=0;
  for(auto x:ed)
  {
    memset(vis,0,sizeof(vis));vis[x.second]=1;
    mx=-1;dfs(x.first,0);
    memset(vis,0,sizeof(vis));vis[x.second]=1;
    mx=-1;dfs(nd,0);long one=mx;
     memset(vis,0,sizeof(vis));vis[x.first]=1;
    mx=-1;dfs(x.second,0);
    memset(vis,0,sizeof(vis));vis[x.first]=1;
    mx=-1;dfs(nd,0);long two=mx;
     //cout<<x.first<<" "<<x.second<<" "<<one<<" "<<two<<endl;
     ans=max(ans,one*two);
  }
  cout<<ans<<endl;
  return 0;
}