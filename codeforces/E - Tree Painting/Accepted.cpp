/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/30/2019 22:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 156 ms                                          memory_used: 17600 KB                             
*  problem: https://codeforces.com/contest/1187/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
vector<int>adj[N+2];
long sub[N+2],sum[N+2],ans,n;
void reckon(int node,int par)
{
  sub[node]=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    reckon(x,node);
    sub[node]+=sub[x];sum[node]+=sum[x];
  }
  sum[node]+=sub[node];
}
void dfs(int node,int par,long ex)
{
  ans=max(ans,sum[node]+ex);
  //cout<<node<<" -- "<<sum[node]+ex<<endl;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,ex+sum[node]-sum[x]-sub[x]-sub[x]+n);
  }
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
  reckon(1,-1);dfs(1,-1,0);
  cout<<ans<<endl;
  return 0;
}