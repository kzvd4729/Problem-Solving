/****************************************************************************************
*  @author: kzvd4729                                         created: May/18/2018 20:58                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 171 ms                                          memory_used: 7200 KB                              
*  problem: https://codeforces.com/contest/982/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,u,v,cnt,sz[N+2];
vector<int>adj[N+2];
int dfs(int node,int pre)
{
  sz[node]=1;
  for(auto x:adj[node])
  {
    if(x==pre)continue;
    sz[node]+=dfs(x,node);
  }
  if(sz[node]%2==0)cnt++;
  return sz[node];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<n;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1);
  if(sz[1]%2)cout<<-1<<endl;
  else cout<<cnt-1<<endl;
  return 0;
}