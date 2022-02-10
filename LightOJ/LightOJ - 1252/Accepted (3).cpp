/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-29 17:32:16                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 21                                         memory_used (MB): 2.3                             
*  problem: https://vjudge.net/problem/LightOJ-1252
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
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
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n>>k;
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v,w;cin>>u>>v>>w;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
    for(int i=0;i<=k;i++)
      for(int j=0;j<=k;j++)
        dp[i][j]=inf;
    dfs(1,-1);
    cout<<"Case "<<++tc<<": "<<1+dp[1][k]<<"\n";
  }
  return 0;
}