/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/16/2018 15:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 21200 KB                             
*  problem: https://codeforces.com/contest/580/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int cat[N+2],m,ans;
vector<int>adj[N+2];
void dfs(int node,int par,int cnt)
{
  if(!cat[node])cnt=0;
  else cnt++;int f=0;
  if(cnt>m)return ;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    f=1;dfs(x,node,cnt);
  }
  if(!f)ans++;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>cat[i];
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1,0);cout<<ans<<endl;
  return 0;
}