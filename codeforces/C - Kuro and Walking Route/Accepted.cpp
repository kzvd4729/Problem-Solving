/****************************************************************************************
*  @author: kzvd4729                                         created: May/14/2018 22:02                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 483 ms                                          memory_used: 28900 KB                             
*  problem: https://codeforces.com/contest/979/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=3e5;
long sz[N+2],u,v,n,x,y,f;
vector<long>adj[N+2];
long dfs(int node,int par)
{
  sz[node]=1;
  if(node==y)f=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    sz[node]+=dfs(x,node);
  }
  return sz[node];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>x>>y;
  for(int i=1;i<n;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  long szz=1;
  for(auto xx:adj[x])
  {
    f=0;
    long ss=dfs(xx,x);
    if(f)ss=0;
    szz+=ss;
  }
   long tt=n*1LL*(n-1)*1LL;
   ///cout<<szz<<" "<<sz[y]<<endl;
   long here=sz[y]*1LL*szz*1LL;
  cout<<tt-here<<endl;
   return 0;
}