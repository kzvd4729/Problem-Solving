/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-29 17:35:12                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 20                                         memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1252
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e2;
const int inf=1e9;
vector<pair<int,int> >adj[N+2];
int dp[N+2][N+2],k;
void dfs(int node,int par)
{
  vector<pair<int,int> >v;
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    dfs(x.first,node);v.push_back(x);
  }
  if(v.size()==0)
  {
    for(int i=0;i<=k;i++)dp[node][i]=0;
    return ;
  }
  int x=v[0].first,y=v[0].second;
  for(int i=0;i<=k;i++)
  {
    dp[node][i]=dp[x][k]+1;
    if(i>=y)dp[node][i]=min(dp[node][i],dp[x][i-y]);
  }
  for(int l=1;l<v.size();l++)
  {
    int x=v[l].first,y=v[l].second;
    for(int i=k;i>=0;i--)
    {
      dp[node][i]+=dp[x][k]+1;
      for(int j=y;j<=i;j++)
      {
        dp[node][i]=min(dp[node][i],dp[node][i-j]+dp[x][j-y]);
      }
    }
  }
}
int main()
{
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    int n;scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v,w;scanf("%d%d%d",&u,&v,&w);
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
    for(int i=0;i<=k;i++)
      for(int j=0;j<=k;j++)
        dp[i][j]=inf;
    dfs(1,-1);printf("Case %d: %d\n",++tc,1+dp[1][k]);
  }
  return 0;
}