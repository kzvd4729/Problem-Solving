/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/30/2018 01:59                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 35500 KB                             
*  problem: https://codeforces.com/contest/544/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e8;
int n,m,u,v,s1,t1,l1,s2,t2,l2;
int dp[3003][3003];
vector<int>adj[3003];
int dfs(int n1,int n2,int r1,int r2,int p1,int p2)
{
  if(r1<0||r2<0)return inf;
  if(n1==t1&&n2==t2)return 0;
  if(dp[n1][n2]!=-1)return dp[n1][n2];
  dp[n1][n2]=inf;
  int here=inf;
  for(auto x:adj[n1])
  {
    if(x==p1)continue;
    here=min(here,1+dfs(x,n2,r1-1,r2,n1,p2));
  }
  for(auto x:adj[n2])
  {
    if(x==p2)continue;
    here=min(here,1+dfs(n1,x,r1,r2-1,p1,n2));
  }
  if(n1==n2)
  {
    for(auto x:adj[n2])
    {
      if(x==p1||x==p2)continue;
      here=min(here,1+dfs(x,x,r1-1,r2-1,n1,n2));
    }
  }
  return dp[n1][n2]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin>>s1>>t1>>l1>>s2>>t2>>l2;
  memset(dp,-1,sizeof(dp));
  int ans=dfs(s1,s2,l1,l2,-1,-1);
  if(ans==inf)cout<<-1<<endl;
  else cout<<m-ans<<endl;
  return 0;
}