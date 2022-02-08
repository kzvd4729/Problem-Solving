/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-19 18:42:08                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 232 ms                                          memory_used: 430464 KB                            
*  problem: https://atcoder.jp/contests/abc152/tasks/abc152_f
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int parn[N+2],lv[N+2],n;
vector<int>adj[50+2];
map<pair<int,int>,int>mp;
long dp[52][(1<<20)+2];
void dfs(int node,int par,int l)
{
  parn[node]=par,lv[node]=l;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,l+1);
  }
}
int pre[N+2];
void upd(int u,int v,int id)
{
  if(u>v)swap(u,v);
  pre[mp[{u,v}]]|=(1<<(id-1));
}
void lca(int u,int v,int id)
{
  if(lv[u]<lv[v])swap(u,v);
  while(lv[u]>lv[v])
  {
    upd(u,parn[u],id);
    u=parn[u];
  }
  while(u!=v)
  {
    upd(u,parn[u],id);u=parn[u];
     upd(v,parn[v],id);v=parn[v];
  }
}
int q;
long dfs(int i,int msk)
{
  if(i==n)return (msk==((1<<q)-1));
  if(dp[i][msk]!=-1)return dp[i][msk];
  return dp[i][msk]=dfs(i+1,msk)+dfs(i+1,msk|pre[i]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;if(u>v)swap(u,v);
    adj[u].push_back(v);adj[v].push_back(u);
    mp[{u,v}]=i;
  }
  dfs(1,-1,0);
  cin>>q;
  for(int i=1;i<=q;i++)
  {
    int u,v;cin>>u>>v;lca(u,v,i);
  }
  // for(int i=1;i<n;i++)
  //   cout<<pre[i]<<" ** ";
  // cout<<endl;
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0)<<endl;
  return 0;
}