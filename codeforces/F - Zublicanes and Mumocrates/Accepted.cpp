/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2019 11:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 156 ms                                          memory_used: 196200 KB                            
*  problem: https://codeforces.com/contest/581/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
int dp[N+2][N+2][2],n,cnt,sub[N+2];
vector<int>adj[N+2];
void dfs(int node,int par)
{
  if(adj[node].size()==1)
  {
    dp[node][1][0]=0;dp[node][0][1]=0;
    sub[node]=1;return ;
  }
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);sub[node]+=sub[x];
  }
  int f=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(!f)
    {
      for(int j=0;j<=min(cnt,sub[node]);j++)
      {
        dp[node][j][0]=min(dp[x][j][0],dp[x][j][1]+1);
        dp[node][j][1]=min(dp[x][j][1],dp[x][j][0]+1);
      }
      f=1;continue;
    }
    for(int j=min(cnt,sub[node]);j>=0;j--)
    {
      int mn1=1e9,mn2=1e9;
      for(int k=0;k<=min(j,sub[x]);k++)
      {
        mn1=min(mn1,dp[x][k][0]+dp[node][j-k][0]);
        mn1=min(mn1,dp[x][k][1]+1+dp[node][j-k][0]);
         mn2=min(mn2,dp[x][k][1]+dp[node][j-k][1]);
        mn2=min(mn2,dp[x][k][0]+1+dp[node][j-k][1]);
      }
      dp[node][j][0]=mn1;dp[node][j][1]=mn2;
    }
  }
  return ;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int rt=-1;
  for(int i=1;i<=n;i++)
  {
    if(adj[i].size()==1)cnt++;
    else if(rt==-1)rt=i;
  }
  if(rt==-1)cout<<1<<endl,exit(0);
  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      dp[i][j][0]=1e9,dp[i][j][1]=1e9;
  cnt/=2;dfs(rt,-1);
  cout<<min(dp[rt][cnt][0],dp[rt][cnt][1])<<endl;
  return 0;
}