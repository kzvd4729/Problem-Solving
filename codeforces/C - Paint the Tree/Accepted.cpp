/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/07/2019 18:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 811 ms                                          memory_used: 66000 KB                             
*  problem: https://codeforces.com/contest/1240/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
vector<pair<int,int> >adj[N+2];
long dp[N+2][2],k;
void dfs(int node,int par,int cs)
{
  set<int>a,b;
  for(auto &x:adj[node])
  {
    if(x.first==par)continue;
    dfs(x.first,node,x.second);
    a.insert(x.first);
  }
  b=a;
  priority_queue<pair<int,int> >pq;
  for(auto &x:a)
    pq.push({dp[x][1]-dp[x][0],x});
  int cnt=k;
  while(cnt--&&pq.size())
  {
    pair<int,int>p=pq.top();pq.pop();
    dp[node][0]+=dp[p.second][1];a.erase(p.second);
  }
  for(auto &x:a)dp[node][0]+=dp[x][0];
  while(pq.size())pq.pop();
   for(auto &x:b)
    pq.push({dp[x][1]-dp[x][0],x});
  cnt=k-1;
  while(cnt--&&pq.size())
  {
    pair<int,int>p=pq.top();pq.pop();
    dp[node][1]+=dp[p.second][1];b.erase(p.second);
  }
  for(auto &x:b)dp[node][1]+=dp[x][0];
  dp[node][1]+=cs;
   dp[node][1]=max(dp[node][1],dp[node][0]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
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
    for(int i=1;i<=n;i++)
      dp[i][0]=0,dp[i][1]=0;
    dfs(1,-1,0);cout<<dp[1][0]<<endl;
  }
  return 0;
}