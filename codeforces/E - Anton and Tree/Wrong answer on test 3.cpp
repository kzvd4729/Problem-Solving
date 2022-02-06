/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2018 22:23                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/734/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,cl[N+2],vis[N+2];
vector<int>adj[N+2];
void dfs(int node)
{
  vis[node]=1;
  for(auto xx:adj[node])
  {
    if(vis[xx])continue;
    dfs(xx);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>cl[i];
  for(int i=2;i<=n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++)
    vis[i]=cl[i];
  int cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    dfs(i);
    cnt++;
  }
  int ans=cnt;
  for(int i=1;i<=n;i++)
    vis[i]=cl[i]^1;
  cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    dfs(i);
    cnt++;
  }
  cout<<min(ans,cnt)<<endl;
  return 0;
}