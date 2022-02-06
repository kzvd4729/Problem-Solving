/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2019 21:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 374 ms                                          memory_used: 43700 KB                             
*  problem: https://codeforces.com/contest/1167/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],vis[N+2],ans[N+2],cnt;
vector<int>adj[N+2],nd;
void dfs(int node)
{
  vis[node]=1;cnt++;nd.push_back(node);
  for(auto x:adj[node])
    if(!vis[x])dfs(x);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  while(m--)
  {
    int x;cin>>x;
    for(int i=1;i<=x;i++)
    {
      cin>>aa[i];if(i==1)continue;
      adj[aa[i]].push_back(aa[i-1]);
      adj[aa[i-1]].push_back(aa[i]);
    }
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;nd.clear();cnt=0;
    dfs(i);for(auto x:nd)ans[x]=cnt;
  }
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}