/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/13/2019 21:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 33100 KB                             
*  problem: https://codeforces.com/contest/1153/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int sts[N+2],vl[N+2];
int sz[N+2],k;
vector<int>adj[N+2];
void reckon(int node)
{
  if(adj[node].size()==0)
  {
    sz[node]=1;return ;
  }
  for(auto x:adj[node])
  {
    reckon(x);sz[node]+=sz[x];
  }
}
void dfs(int node)
{
  if(adj[node].size()==0)
  {
    vl[node]=k;return ;
  }
  for(auto x:adj[node])
    dfs(x);
  if(sts[node])
  {
    vl[node]=0;
    for(auto x:adj[node])
      vl[node]=max(vl[node],vl[x]);
  }
  else
  {
    int ad=0;
    for(auto x:adj[node])
      ad+=(k-vl[x]+1);
    vl[node]=k-ad+1;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>sts[i];
  for(int i=2;i<=n;i++)
  {
    int x;cin>>x;adj[x].push_back(i);
  }
  reckon(1);k=sz[1];//cout<<k<<endl;
  dfs(1);cout<<vl[1]<<endl;
    return 0;
}