/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/22/2019 20:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 23600 KB                             
*  problem: https://codeforces.com/contest/1249/problem/B1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],vis[N+2],ans[N+2];
vector<int>adj[N+2],v;
void dfs(int node)
{
  v.push_back(node);vis[node]=1;
  for(auto x:adj[node])
    if(!vis[x])dfs(x);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>q;
  while(q--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)adj[i].clear(),vis[i]=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      adj[i].push_back(x);
    }
     for(int i=1;i<=n;i++)
    {
      if(vis[i])continue;
      v.clear();dfs(i);
      for(int j=0;j<v.size();j++)
        ans[v[j]]=v.size();
    }
    for(int i=1;i<=n;i++)
      cout<<ans[i]<<" ";
    cout<<"\n";
   }
  return 0;
}