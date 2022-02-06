/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/16/2019 20:50                        
*  solution_verdict: Time limit exceeded on test 19          language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 196200 KB                            
*  problem: https://codeforces.com/contest/581/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
int dp[N+2][N+2][2],n,cnt;
vector<int>adj[N+2];
/*********** Centroid Decomposition ************/
int Tot,Mark[N+2],Sz[N+2];
void Reckon(int node,int par)
{
  Tot++;Sz[node]=1;
  for(auto x:adj[node])
  {
    if(Mark[x]||x==par)continue;
    Reckon(x,node);Sz[node]+=Sz[x];
  }
}
int Find_Center(int node,int par)
{
  for(auto x:adj[node])
  {
    if(x==par||Mark[x])continue;
    if(Sz[x]>Tot/2)return Find_Center(x,node);
  }
  return node;
}
/////////////////////////////////////////////////
int dfs(int node,int par)
{
  if(adj[node].size()==1)
  {
    dp[node][1][0]=0;dp[node][0][1]=0;
    return 1;
  }
  int mx=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    mx+=dfs(x,node);
  }
  int f=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(!f)
    {
      for(int j=0;j<=min(cnt,mx);j++)
      {
        dp[node][j][0]=min(dp[x][j][0],dp[x][j][1]+1);
        dp[node][j][1]=min(dp[x][j][1],dp[x][j][0]+1);
      }
      f=1;continue;
    }
    for(int j=min(cnt,mx);j>=0;j--)
    {
      int mn1=1e9,mn2=1e9;
      for(int k=0;k<=j;k++)
      {
        mn1=min(mn1,dp[x][k][0]+dp[node][j-k][0]);
        mn1=min(mn1,dp[x][k][1]+1+dp[node][j-k][0]);
         mn2=min(mn2,dp[x][k][1]+dp[node][j-k][1]);
        mn2=min(mn2,dp[x][k][0]+1+dp[node][j-k][1]);
      }
      dp[node][j][0]=mn1;dp[node][j][1]=mn2;
    }
  }
  return mx;
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
  if(rt==-1)cout<<0<<endl,exit(0);
  Reckon(1,-1);rt=Find_Center(1,-1);
  //cout<<rt<<endl;
  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      dp[i][j][0]=1e9,dp[i][j][1]=1e9;
  cnt/=2;dfs(rt,-1);
  cout<<min(dp[rt][cnt][0],dp[rt][cnt][1])<<endl;
  return 0;
}