/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2018 16:28                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 654 ms                                          memory_used: 36200 KB                             
*  problem: https://codeforces.com/contest/219/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,u,v,sz[N+2],rev[N+2];
vector<int>adj[N+2],ans[N+2];
map<pair<int,int>,int>mp;
void dfs(int node,int par)
{
  sz[node]=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);
    sz[node]+=sz[x];
    rev[node]+=rev[x];
    if(!mp[{node,x}])rev[node]++;
  }
}
void dds(int node,int par,int cnt)
{
  ans[cnt].push_back(node);
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(mp[{node,x}])dds(x,node,cnt+1);
    else dds(x,node,cnt-1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<n;i++)
  {
    cin>>u>>v;
    mp[{u,v}]=1;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1);
  for(int i=1;i<=n;i++)sz[i]--;
  dds(1,-1,rev[1]);
  for(int i=0;i<=N;i++)
  {
    if(ans[i].size())
    {
      cout<<i<<endl;
      for(auto x:ans[i])
        cout<<x<<" ";
      cout<<endl;
      return 0;
    }
  }
  return 0;
}