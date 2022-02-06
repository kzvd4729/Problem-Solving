/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/12/2020 20:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 32900 KB                             
*  problem: https://codeforces.com/contest/1324/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int cl[N+2],sub[N+2],ans[N+2];
vector<int>adj[N+2];
void dfs(int node,int par)
{
  sub[node]=1;
  if(!cl[node])sub[node]=-1;
   for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);sub[node]+=max(0,sub[x]);
  }
}
void dds(int node,int par,int ad)
{
  ad=max(ad,0);
  //cout<<node<<" ** "<<ad<<endl;
  ans[node]=sub[node]+ad;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dds(x,node,ad+sub[node]-max(0,sub[x]));
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>cl[i];
   for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,-1);dds(1,-1,0);
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
  return 0;
}