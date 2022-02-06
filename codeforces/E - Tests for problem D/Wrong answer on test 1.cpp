/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/19/2019 22:34                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1278/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int sz[N+2];
vector<int>adj[N+2];
vector<pair<int,int> >ed;
void rk(int node,int par)
{
  sz[node]=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    rk(x,node);sz[node]+=sz[x];
  }
}
void dfs(int node,int par,int lo,int hi)
{
  int ch=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    ch++;
  }
  int thi=hi-ch,tlo=lo+1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    ed.push_back({tlo,hi--});
    dfs(x,node,tlo,tlo+sz[x]*2-2);
    tlo+=sz[x]*2-2+1;
  }
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
  rk(1,-1);ed.push_back({1,2*n-adj[1].size()});
  dfs(1,-1,1,2*n);
  for(auto x:ed)
    cout<<x.first<<" "<<x.second<<endl;
  return 0;
}