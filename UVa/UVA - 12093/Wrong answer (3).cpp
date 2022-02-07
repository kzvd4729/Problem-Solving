/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-30 19:50:59                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12093
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e4,inf=1e9;
long n,a,b,dp[N+2][3],tmp[N+2][2];
vector<long>adj[N+2],nx[N+2];
void dfs(long node,long par)
{
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);nx[node].push_back(x);
  }
  dp[node][0]=0;dp[node][1]=min(a,b);dp[node][2]=b;
  if(nx[node].size()==0)return ;
  for(auto x:nx[node])
    dp[node][0]+=dp[x][1];
  for(auto x:nx[node])
    dp[node][1]+=min(dp[x][1],dp[x][0]);
  for(long i=0;i<nx[node].size();i++)
    tmp[i][0]=inf,tmp[i][1]=inf;
  long x=nx[node].back();
  tmp[nx[node].size()-1][1]=dp[x][2];
  tmp[nx[node].size()-1][0]=min(dp[x][1],dp[x][0]);
  tmp[nx[node].size()-1][0]=min(tmp[nx[node].size()-1][0],tmp[nx[node].size()-1][1]);
  for(long i=nx[node].size()-2;i>=0;i--)
  {
    x=nx[node][i];
    tmp[i][1]=tmp[i+1][1]+min(dp[x][0],dp[x][1]);
    tmp[i][1]=min(tmp[i][1],dp[x][2]+tmp[i+1][0]);
    tmp[i][0]=min(dp[x][0],dp[x][1])+tmp[i+1][0];
    tmp[i][0]=min(tmp[i][0],tmp[i][1]);
  }
  dp[node][1]=min(dp[node][1],tmp[0][1]);
  dp[node][2]=b;
  for(auto x:nx[node])
    for(auto z:nx[x])
      dp[node][2]+=min(dp[z][1],dp[z][0]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  while(cin>>n>>a>>b)
  {
    if(!(n+a+b))break;
    for(long i=1;i<=n;i++)adj[i].clear(),nx[i].clear();
    for(long i=1;i<n;i++)
    {
      long u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for(long i=1;i<=n;i++)
      for(long j=0;j<3;j++)dp[i][j]=inf;
    dfs(1,-1);cout<<min(dp[1][0],min(dp[1][1],dp[1][2]))<<endl;
  }
  return 0;
}