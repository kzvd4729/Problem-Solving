/****************************************************************************************
*  @author: kzvd4729                                         created: May/01/2020 11:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 21100 KB                             
*  problem: https://codeforces.com/contest/655/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#define long long long
using namespace std;
const int N=1e6;
int dp[N+2];
vector<int>adj[N+2];
int dfs(int node)
{
  if(dp[node]!=-1)return dp[node];
  dp[node]=0;
  for(auto x:adj[node])
    dp[node]=max(dp[node],dfs(x));
  return ++dp[node];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  vector<pair<int,int> >ed;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    ed.push_back({u,v});
  }
  memset(dp,-1,sizeof dp);
  int ans=-1,rt;
  for(int i=1;i<=n;i++)
  {
    int now=dfs(i);
    if(now>ans)ans=now,rt=i;
  }
  if(ans!=n)cout<<-1<<endl,exit(0);
  int cnt=m;
  //for(int i=1;i<=n;i++)cout<<dp[i]<<" ";cout<<endl;
  for(int i=m-1;i>=0;i--)
  {
    if(dp[ed[i].first]-1==dp[ed[i].second])break;
    cnt--;
  }
  cout<<cnt<<endl;
  return 0;
}