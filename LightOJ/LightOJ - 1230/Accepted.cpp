/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-15 20:30:49                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 3                                          memory_used (MB): 2.3                             
*  problem: https://vjudge.net/problem/LightOJ-1230
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int vis[N+2],dp[N+2][2],mx[N+2][2];
vector<int>adj[N+2];
void dfs(int node,int par)
{
  int ter=1;vis[node]=1;
  for(int i=0;i<adj[node].size();i++)
  {
    int x=adj[node][i];
    if(x==par)continue;ter=0;
    dfs(x,node);
  }
  dp[node][1]=1;if(ter)return ;
  for(int i=0;i<adj[node].size();i++)
  {
    int x=adj[node][i];
    if(x==par)continue;
    dp[node][0]+=dp[x][1];mx[node][0]+=mx[x][1];
    dp[node][1]+=min(dp[x][1],dp[x][0]);

    if(dp[x][0]<dp[x][1])mx[node][1]+=mx[x][0];
    else if(dp[x][1]<dp[x][0])mx[node][1]+=mx[x][1]+1;
    else mx[node][1]+=max(mx[x][0],mx[x][1]+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)adj[i].clear(),vis[i]=0;
    for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;u++,v++;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    memset(dp,0,sizeof(dp));
    memset(mx,0,sizeof(mx));
    int ans=0,two=0;
    for(int i=1;i<=n;i++)
    {
      if(vis[i])continue;dfs(i,-1);
      ans+=min(dp[i][0],dp[i][1]);

      if(dp[i][0]<dp[i][1])two+=mx[i][0];
      else if(dp[i][1]<dp[i][0])two+=mx[i][1];
      else two+=max(mx[i][0],mx[i][1]);
    }
    cout<<"Case "<<++tc<<": "<<ans<<" "<<two<<" "<<m-two<<"\n";
  }
  return 0;
}