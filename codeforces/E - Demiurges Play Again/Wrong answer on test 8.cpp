/****************************************************************************************
*  @author: kzvd4729                                         created: May/04/2020 11:42                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 15800 KB                             
*  problem: https://codeforces.com/contest/538/problem/E
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
#define long long long
using namespace std;
const int N=1e6,mod=1e9+9;
vector<int>adj[N+2];
int sz[N+2];
void dfs(int node)
{
  for(auto x:adj[node])
  {
    dfs(x);sz[node]+=sz[x];
  }
  if(!sz[node])sz[node]=1;
}
int dfs1(int node,int tr,int lo,int hi)
{
  if(adj[node].size()==0)
  {
    assert(lo==hi);return lo;
  }
  int now=0;
  if(tr)
  {
    for(auto x:adj[node])
      now=max(now,dfs1(x,tr^1,hi-sz[x]+1,hi));
  }
  else
  {
    for(auto x:adj[node])
      now=max(now,dfs1(x,tr^1,lo,lo+sz[x]-1));
  }
  return now;
}
int dfs2(int node,int tr,int lo,int hi)
{
  if(adj[node].size()==0)
  {
    assert(lo==hi);return lo;
  }
  int now=1e9;
  if(tr)
  {
    for(auto x:adj[node])
      now=min(now,dfs2(x,tr^1,hi-sz[x]+1,hi));
  }
  else
  {
    for(auto x:adj[node])
      now=min(now,dfs2(x,tr^1,lo,lo+sz[x]-1));
  }
  return now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;adj[u].push_back(v);
  }
  dfs(1);cout<<dfs1(1,1,1,sz[1])<<" "<<dfs2(1,1,1,sz[1])<<endl;
  return 0;
}