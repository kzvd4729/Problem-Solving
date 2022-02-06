/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/29/2018 15:09                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 7100 KB                              
*  problem: https://codeforces.com/contest/618/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int mx,nx;
vector<int>adj[N+2];
void dfs(int node,int par,int ds)
{
  if(ds>mx)
  {
    mx=ds;nx=node;
  }
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,ds+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,x,y;cin>>n>>x>>y;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1,0);dfs(nx,-1,0);
  if(y<x)cout<<(n-1)*1LL*y<<endl;
  else cout<<(mx*1LL*x)+(n-1-mx)*1LL*y<<endl;
   return 0;
}