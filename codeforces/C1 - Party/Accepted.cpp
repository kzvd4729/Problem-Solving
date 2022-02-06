/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/20/2018 19:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 27500 KB                             
*  problem: https://codeforces.com/contest/177/problem/C1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2];
vector<int>adj[N+2],bad[N+2],v;
void dfs(int node)
{
  v.push_back(node);vis[node]=1;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    dfs(x);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  while(m--)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int k;cin>>k;
  while(k--)
  {
    int u,v;cin>>u>>v;
    bad[u].push_back(v);
    bad[v].push_back(u);
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    v.clear();if(vis[i])continue;
    dfs(i);int f=0;
    for(int x:v)
    {
      for(auto z:bad[x])
      {
        if(binary_search(v.begin(),v.end(),z))
        {
          f=1;break;
        }
      }
      if(f)break;
    }
    if(f==0)ans=max(ans,(int)v.size());
  }
  cout<<ans<<endl;
  return 0;
}