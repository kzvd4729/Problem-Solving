/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/02/2019 18:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 248 ms                                          memory_used: 10000 KB                             
*  problem: https://codeforces.com/contest/321/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
 int sz[N+2],mark[N+2],tot,vis[N+2];
vector<int>adj[N+2];
void reckon(int n,int p)
{
  tot++;sz[n]=1;
  for(auto x:adj[n])
  {
    if(x==p||mark[x])continue;
    reckon(x,n);sz[n]+=sz[x];
  }
}
int center(int n,int p)
{
  for(auto x:adj[n])
  {
    if(x==p||mark[x])continue;
    if(sz[x]>tot/2)return center(x,n);
  }
  return n;
}
void dfs(int n,int p,int c)
{
  tot=0;reckon(n,-1);int cen=center(n,-1);
  mark[cen]=1;vis[cen]=c;
   for(auto x:adj[cen])
    if(!mark[x])dfs(x,cen,c+1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,-1,0);
  for(int i=1;i<=n;i++)
   cout<<(char)(vis[i]+'A')<<" ";
  cout<<endl;
  return 0;
}