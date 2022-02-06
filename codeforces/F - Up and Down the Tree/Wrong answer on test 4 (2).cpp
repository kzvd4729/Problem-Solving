/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/11/2019 15:19                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/1065/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int dis[N+2],dp[N+2][2],k;
vector<int>adj[N+2];
void dfs(int node)
{
  if(adj[node].size())dis[node]=1e9;
  else dp[node][0]=dp[node][1]=1;
  int mx=0;
  for(auto x:adj[node])
  {
    dfs(x);
    dis[node]=min(dis[node],dis[x]+1);
    if(dis[x]+1<=k)dp[node][0]+=dp[x][0];
    else mx=max(mx,dp[x][1]);
  }
  dp[node][1]=dp[node][0]+mx;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n>>k;
  for(int i=2;i<=n;i++)
  {
    int x;cin>>x;adj[x].push_back(i);
  }
  dfs(1);cout<<dp[1][1]<<endl;
  return 0;
}