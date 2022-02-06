/****************************************************************************************
*  @author: kzvd4729                                         created: May/06/2020 21:28                        
*  solution_verdict: Wrong answer on pretest 5               language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 31200 KB                             
*  problem: https://codeforces.com/contest/1344/problem/C
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#define long long long
using namespace std;
const int N=1e6;
 int vis[N+2];
vector<int>adj[N+2],rv[N+2],ord,com;
void topo(int node)
{
  vis[node]=1;
  for(auto x:adj[node])
    if(!vis[x])topo(x);
  ord.push_back(node);
}
void dfs(int node)
{
  com.push_back(node);vis[node]=1;
  for(auto x:rv[node])
    if(!vis[x])dfs(x);
}
int solve(int n)
{
  for(int i=1;i<=n;i++)
    if(!vis[i])topo(i);
  for(int i=1;i<=n;i++)vis[i]=0;
  int scc=0;
  for(int i=n-1;i>=0;i--)
  {
    if(vis[ord[i]])continue;
    com.clear();dfs(ord[i]);scc++;
  }
  return scc;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int a,b;cin>>a>>b;
    adj[b].push_back(a);rv[a].push_back(b);
  }
  int scc=solve(n);if(scc<n)cout<<-1<<endl,exit(0);
  int lf=0;
  for(int i=1;i<=n;i++)if(adj[i].size()==0)lf++;
  cout<<lf<<endl;
  for(int i=1;i<=n;i++)
  {
    if(adj[i].size()==0)cout<<'A';
    else cout<<'E';
  }
  cout<<endl;
  return 0;
}