/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/23/2020 18:42                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 639 ms                                          memory_used: 43600 KB                             
*  problem: https://codeforces.com/contest/1280/problem/C
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
#define long long long  
using namespace std;
const int N=1e6;
vector<pair<int,int> >adj[N+2];
long sm,bg;int vis[N+2],sz[N+2],n;
void dfs(int node,int par)
{
  sz[node]=1;
  for(auto x:adj[node])
  {
    if(x.first!=par)dfs(x.first,node),sz[node]+=sz[x.first];
  }
  int cnt=0;
  for(auto x:adj[node])
  {
    if(x.first==par||vis[x.first])continue;
    sm+=x.second;cnt++;
  }
  vis[node]=cnt%2;
}
void dds(int node,int par)
{
  for(auto x:adj[node])
  {
    if(x.first!=par)
      dds(x.first,node),bg+=1LL*x.second*min(sz[x.first],n-sz[x.first]);
  }
}
void solve()
{
  cin>>n;n+=n;
  for(int i=1;i<=n;i++)adj[i].clear(),vis[i]=0;
  for(int i=1;i<n;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  sm=0,bg=0;dfs(1,-1);dds(1,-1);
  //for(int i=1;i<=n;i++)cout<<sz[i]<<" && ";cout<<endl;
  cout<<sm<<" "<<bg<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}