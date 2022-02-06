/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/17/2019 16:00                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 19600 KB                             
*  problem: https://codeforces.com/contest/788/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int sz[N+2],vis[N+2],cnt;
vector<int>adj[N+2];
void dfs(int n)
{
  cnt++;vis[n]=1;
  for(auto x:adj[n])
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
    if(u!=v)adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++)sz[i]=adj[i].size();
  long ans=0;dfs(1);
  if(cnt!=n)cout<<0<<endl,exit(0);
  for(int i=1;i<=n;i++)
    for(auto x:adj[i])
      ans+=(sz[x]-1)*1LL;
  if(ans%2)assert(0);
  cout<<ans/2<<endl;
  return 0;
}