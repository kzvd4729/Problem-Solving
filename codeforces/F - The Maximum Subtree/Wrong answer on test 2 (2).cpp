/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/09/2019 23:51                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 248 ms                                          memory_used: 19700 KB                             
*  problem: https://codeforces.com/contest/1238/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>adj[N+2];
int dp[N+2][2],ans;
void dfs(int node,int par)
{
  dp[node][0]=1;priority_queue<int>pq;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);pq.push(dp[x][0]);
  }
  if(pq.size()){dp[node][0]+=pq.top();pq.pop();}
  dp[node][1]=dp[node][0];dp[node][1]+=pq.size();
  if(pq.size()){dp[node][1]+=pq.top();pq.pop();}
  dp[node][1]+=pq.size();if(par!=-1)dp[node][1]++;
  ans=max(ans,dp[node][1]);
  //cout<<node<<" --> "<<dp[node][0]<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    ans=0;dfs(1,-1);cout<<ans<<endl;
  }
  return 0;
}