/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/14/2019 20:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 26200 KB                             
*  problem: https://codeforces.com/contest/1176/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>adj[N+2],ans[3];
int vis[N+2];
void dfs(int node,int cl)
{
  ans[cl].push_back(node);
  vis[node]=1;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    dfs(x,cl^1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)adj[i].clear(),vis[i]=0;
    while(m--)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    ans[0].clear();ans[1].clear();
    dfs(1,0);
    if(ans[0].size()<ans[1].size())ans[2]=ans[0];
    else ans[2]=ans[1];
    cout<<ans[2].size()<<"\n";
    for(auto x:ans[2])
      cout<<x<<" ";
    cout<<"\n";
  }
  return 0;
}