/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/17/2019 16:18                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 27400 KB                             
*  problem: https://codeforces.com/contest/788/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long sz[N+2],vis[N+2],cnt;
vector<long>adj[N+2];
void dfs(long n)
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
  long n,m;cin>>n>>m;
  while(m--)
  {
    long u,v;cin>>u>>v;
    adj[u].push_back(v);
    if(u!=v)adj[v].push_back(u);
  }
  for(long i=1;i<=n;i++)sz[i]=adj[i].size();
  long ans=0;dfs(1);
  if(cnt!=n)cout<<0<<endl,exit(0);
  for(long i=1;i<=n;i++)
    ans+=((sz[i]*(sz[i]-1))/2);
  cout<<ans<<endl;
  return 0;
}