/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/12/2018 14:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 98600 KB                             
*  problem: https://codeforces.com/contest/721/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3,inf=1e9+9;
int n,m,t,dp[N+2][N+2],vis[N+2];
vector<pair<int,int> >adj[N+2];
vector<int>ans;
void dfs(int node)
{
  if(vis[node])return ;
  vis[node]=1;
  if(node==n)
  {
    dp[node][1]=0;
    return ;
  }
  for(auto x:adj[node])
  {
    dfs(x.first);
    for(int i=2;i<=N;i++)
      dp[node][i]=min(dp[node][i],dp[x.first][i-1]+x.second);
  }
}
void path(int node,int mx)
{
  if(node==n)return ;
  for(auto x:adj[node])
  {
    if(dp[node][mx]==dp[x.first][mx-1]+x.second)
    {
      ans.push_back(x.first);
      return path(x.first,mx-1);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>t;
  for(int i=0;i<=N;i++)
    for(int j=0;j<=N;j++)dp[i][j]=inf;
  while(m--)
  {
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
  }
  dfs(1);int mx;
  for(int i=N;i>=1;i--)
  {
    if(dp[1][i]<=t)
    {
      mx=i;break;
    }
  }
  cout<<mx<<endl;ans.push_back(1);
  path(1,mx);
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}