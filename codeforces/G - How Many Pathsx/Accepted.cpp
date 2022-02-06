/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/07/2021 23:53                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 701 ms                                          memory_used: 123800 KB                            
*  problem: https://codeforces.com/contest/1547/problem/G
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
 const int N=4e5,inf=1e9;
 int vis[N+2],bad[N+2],self[N+2];
vector<int>adj[N+2],rv[N+2],ord,com,dag[N+2];
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
 int par[N+2];
vector<int>ch[N+2];
void solve(int n)
{
  for(int i=1;i<=n;i++)
    if(!vis[i])topo(i);
   for(int i=1;i<=n;i++)vis[i]=0;
  for(int i=n-1;i>=0;i--)
  {
    if(vis[ord[i]])continue;
    com.clear();dfs(ord[i]);
     for(int j=0;j<com.size();j++)
    {
      par[com[j]]=com[0];
      ch[com[0]].push_back(com[j]);
    }
    if(com.size()>1)bad[com[0]]=1;
    if(self[com[0]])bad[com[0]]=1;
   }
  set<pair<int,int> >st;
  for(int i=1;i<=n;i++)
  {
    for(auto j:adj[i])
    {
      if(par[i]!=par[j])
        st.insert({par[i],par[j]});
    }
  }
  for(auto x:st)dag[x.first].push_back(x.second);
}
 int cnt[N+2],dp[N+2][2];
void dfs1(int nd,int f)
{
  f|=bad[nd];
   if(dp[nd][f])return;
  dp[nd][f]=1;
   for(auto x:dag[nd])dfs1(x,f);
}
void dfs2(int nd)
{
  if(cnt[nd]==2)return ;
  cnt[nd]++;
   for(auto x:dag[nd])dfs2(x);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
     ord.clear();com.clear();
    for(int i=1;i<=n;i++)
    {
      vis[i]=0,bad[i]=0;adj[i].clear();rv[i].clear();
      self[i]=0;dag[i].clear();ch[i].clear();
      cnt[i]=0,dp[i][0]=0,dp[i][1]=0;
    }
     for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;
      if(u==v)self[u]=1;
      else 
      {
        adj[u].push_back(v);
        rv[v].push_back(u);
        //cout<<u<<" --> "<<v<<endl;
      }
    }
     solve(n);
     int rt=par[1];
    dfs1(rt,0);dfs2(rt);
     for(int i=1;i<=n;i++)
    {
      if(dp[i][1]==1)
      {
        for(auto x:ch[i])dp[x][1]=1;
      }
    }
     for(int i=1;i<=n;i++)
    {
      if(dp[i][1])cout<<-1<<" ";
      else cout<<cnt[i]<<" ";
    }
    cout<<endl;
  }
    return 0;
}