/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2018 16:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 8000 KB                              
*  problem: https://codeforces.com/contest/659/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int ans,u,v,nsz,esz,n,m,cnt[N+2],vis[N+2];
vector<int>adj[N+2];
void dfs(int node)
{
  nsz++;
  esz+=cnt[node];
  vis[node]=1;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    dfs(x);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    cnt[u]++;
    cnt[v]++;
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    nsz=0;
    esz=0;
    dfs(i);
    if(esz>(nsz-1)*2)continue;
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}