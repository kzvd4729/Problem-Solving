/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/05/2018 01:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 108 ms                                          memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/1075/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int aa[N+2],bb[N+2],f,tr,vis[N+2];
vector<int>adj[N+2];
void dfs(int node,int par)
{
  if(vis[node])
  {
    tr=node;
    f=1;return ;
  }
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(f)return ;
    dfs(x,node);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=0;i<=n;i++)adj[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int k1;cin>>k1;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=k1;i++)
    {
      cin>>aa[i];vis[aa[i]]=1;
    }
    int k2;cin>>k2;
    for(int i=1;i<=k2;i++)
      cin>>bb[i];
     cout<<"B "<<bb[1]<<endl;
    fflush(stdout);
    int rt;cin>>rt;f=0;
    dfs(rt,-1);
     cout<<"A "<<tr<<endl;
    fflush(stdout);
    int x;cin>>x;
    f=0;
    for(int i=1;i<=k2;i++)
      if(bb[i]==x)f=1;
    if(f)cout<<"C "<<tr<<endl;
    else cout<<"C "<<-1<<endl;
    fflush(stdout);
  }
  return 0;
}