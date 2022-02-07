/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-03 21:56:15                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11367
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e3,inf=1e9;
long aa[N+2],n,m,cp,st,ed;
long dp[N+2][102];
vector<pair<long,long> >adj[N+2];
long dfs(long node,long cc)
{
  if(node==ed)return 0;
  if(dp[node][cc]!=-1)return dp[node][cc];
  dp[node][cc]=inf;
  if(cc<cp)dp[node][cc]=min(dp[node][cc],aa[node]+dfs(node,cc+1));
  for(auto x:adj[node])
  {
    if(x.second<=cc)
      dp[node][cc]=min(dp[node][cc],dfs(x.first,cc-x.second));
  }
  return dp[node][cc];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  while(cin>>n>>m)
  {
    for(long i=1;i<=n;i++)
    {
      cin>>aa[i];adj[i].clear();
    }
    while(m--)
    {
      long u,v,w;cin>>u>>v>>w;u++,v++;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
    long q;cin>>q;
    while(q--)
    {
      cin>>cp>>st>>ed;st++,ed++;
      memset(dp,-1,sizeof(dp));
      long rs=dfs(st,0);
      if(rs>=inf)cout<<"impossible"<<endl;
      else cout<<rs<<endl;if(rs<0)assert(0);
    }
  }
  return 0;
}