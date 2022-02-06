/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/18/2018 21:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 53400 KB                             
*  problem: https://codeforces.com/contest/1092/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
long cal[N+2],sum[N+2],ans;
vector<int>adj[N+2];
void dfs(int node,int par)
{
  cal[node]=sum[node]=aa[node];
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);sum[node]+=sum[x];
    cal[node]+=cal[x]+sum[x];
  }
}
void dds(int node,int par,long cl,long sm)
{
  ans=max(ans,cal[node]-sum[node]+cl);
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dds(x,node,cl+sm+cal[node]-cal[x]-sum[x],sm+sum[node]-sum[x]);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1);dds(1,-1,0,0);
  cout<<ans<<endl;
  return 0;
}