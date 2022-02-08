/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-01 18:25:14                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 96 ms                                           memory_used: 65020 KB                             
*  problem: https://atcoder.jp/contests/abc157/tasks/abc157_d
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
vector<int>adj[N+2],bl[N+2],v;
int vis[N+2],ans[N+2],tmp[N+2];
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
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
    //bl[u].push_back(v);bl[v].push_back(u);
  }
  for(int i=1;i<=k;i++)
  {
    int u,v;cin>>u>>v;
    bl[u].push_back(v);bl[v].push_back(u);
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;v.clear();
    dfs(i);
    //cout<<v.size()<<endl;
     for(auto x:v)tmp[x]=1;
    for(auto x:v)
    {
      ans[x]=v.size()-adj[x].size()-1;
      for(auto z:bl[x])ans[x]-=tmp[z];
    }
    for(auto x:v)tmp[x]=0;
  }
  cout<<ans[1];
  for(int i=2;i<=n;i++)cout<<" "<<ans[i];
    cout<<endl;
  return 0;
}