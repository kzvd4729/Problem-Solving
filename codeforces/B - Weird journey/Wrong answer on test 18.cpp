/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/17/2019 16:58                        
*  solution_verdict: Wrong answer on test 18                 language: GNU C++14                               
*  run_time: 701 ms                                          memory_used: 73400 KB                             
*  problem: https://codeforces.com/contest/788/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long sz[N+2],vis[N+2],cnt,slf[N+2],inc;
vector<long>adj[N+2];
void dfs(long n)
{
  vis[n]=1;
  for(auto x:adj[n])
  {
    if(vis[x])continue;
    dfs(x);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m;vector<pair<int,int> >ed;
  for(int i=1;i<=m;i++)
  {
    long u,v;cin>>u>>v;
    if(u==v)slf[u]=1,inc++;
    else
    {
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    ed.push_back({u,v});
  }
  for(long i=1;i<=n;i++)sz[i]=adj[i].size();
  long ans=0;dfs(1);
  for(auto x:ed)
    cnt+=(vis[x.first]*vis[x.second]);
  if(cnt!=m)cout<<0<<endl,exit(0);
  for(long i=1;i<=n;i++)
    ans+=((sz[i]*(sz[i]-1))/2);
  ans+=(m-inc)*inc;
  ans+=(inc*(inc-1))/2;
  cout<<ans<<endl;
  return 0;
}