/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/07/2020 23:09                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 842 ms                                          memory_used: 172000 KB                            
*  problem: https://codeforces.com/contest/463/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6,inf=1e9;
int aa[N+2],n,vis[N+2],ans[N+2];
set<int>st[N+2];vector<int>fc[N+2],adj[N+2];
void seive();
void dfs(int node,int par,int l)
{
  for(auto &x:fc[aa[node]])
  {
    if(st[x].size())ans[node]=max(ans[node],*st[x].rbegin());
    st[x].insert(l);
  }
  for(auto x:adj[node])
    if(x!=par)dfs(x,node,l+1);
  for(auto &x:fc[aa[node]])
    if(st[x].find(l)!=st[x].end())st[x].erase(l);
}
void upd()
{
  for(int i=1;i<=n;i++)ans[i]=-1,st[i].clear();
  dfs(1,-1,1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();int q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  upd();
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int v;cin>>v;cout<<ans[v]<<"\n";
    }
    else
    {
      int v,w;cin>>v>>w;aa[v]=w;
      upd();
    }
  }
  return 0;
}
void seive()
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)fc[j].push_back(i),vis[j]=1;
  }
}