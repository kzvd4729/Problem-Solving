/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/20/2020 19:34                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 216 ms                                          memory_used: 23800 KB                             
*  problem: https://codeforces.com/contest/238/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>adj[N+2],sgn[N+2];
int cnt;
void dfs(int node,int par)
{
  for(int i=0;i<adj[node].size();i++)
  {
    if(adj[node][i]==par)continue;
    cnt+=sgn[node][i];dfs(adj[node][i],node);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);sgn[u].push_back(0);
    adj[v].push_back(u);sgn[v].push_back(1);
  }
  int ans=1e9;
  for(int i=1;i<=n;i++)
  {
    cnt=0;dfs(i,-1);ans=min(ans,cnt);
  }
  cout<<max(ans-1,0)<<endl;
  return 0;
}