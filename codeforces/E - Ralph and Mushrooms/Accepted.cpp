/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/20/2019 19:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1372 ms                                         memory_used: 164900 KB                            
*  problem: https://codeforces.com/contest/894/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2],num[N+2];long cost[N+2],dp[N+2],sum[N+2];
vector<int>rv[N+2],ord,v;
vector<pair<int,int> >adj[N+2],dag[N+2];
void topo(int node)
{
  vis[node]=1;
  for(auto x:adj[node])
    if(!vis[x.first])topo(x.first);
  ord.push_back(node);
}
void dfs(int node,int par)
{
  num[node]=par;vis[node]=1;
  for(auto x:rv[node])
    if(!vis[x])dfs(x,par);
}
void solve(int n)
{
  for(int i=1;i<=n;i++)
    if(!vis[i])topo(i);
  for(int i=1;i<=n;i++)vis[i]=0;
  for(int i=n-1;i>=0;i--)
  {
    if(vis[ord[i]])continue;
    dfs(ord[i],ord[i]);
  }
}
long ret(int n)
{
  int id=upper_bound(v.begin(),v.end(),n)-v.begin();
  id--;
  return 1LL*n*(id+1)-sum[id];
}
long rec(int node)
{
  if(dp[node]!=-1)return dp[node]+cost[node];
  dp[node]=0;
  for(auto x:dag[node])
    dp[node]=max(dp[node],rec(x.first)+x.second);
  return dp[node]+cost[node];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  while(m--)
  {
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});rv[v].push_back(u);
  }
  solve(n);
   int sm=0;
  for(int i=1;i<=20000;i++)
  {
    v.push_back(sm);sm+=i;
  }
  for(int i=1;i<v.size();i++)
    sum[i]=sum[i-1]+v[i];
//  for(int i=1;i<=n;i++)
//    cout<<num[i]<<" ** ";
//  cout<<endl;
   for(int i=1;i<=n;i++)
  {
    for(auto x:adj[i])
    {
      if(num[i]==num[x.first])
        cost[num[i]]+=ret(x.second);
      else
        dag[num[i]].push_back({num[x.first],x.second});
    }
  }
  for(int i=1;i<=n;i++)dp[i]=-1;
  int s;cin>>s;cout<<rec(num[s])<<endl;
  return 0;
}