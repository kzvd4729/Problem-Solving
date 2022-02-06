/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/30/2020 13:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 18600 KB                             
*  problem: https://codeforces.com/contest/949/problem/C
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
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],dp[N+2];
vector<int>rl[N+2];
int vis[N+2],con[N+2],sz[N+2];
vector<int>adj[N+2],rv[N+2],ord,com,str[N+2];
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
void solve(int n)
{
  for(int i=1;i<=n;i++)
    if(!vis[i])topo(i);
  for(int i=1;i<=n;i++)vis[i]=0;
  for(int i=n-1;i>=0;i--)
  {
    if(vis[ord[i]])continue;
    com.clear();dfs(ord[i]);
    for(auto x:com)con[x]=com[0],sz[x]=com.size(),str[com[0]].push_back(x);
  }
}
int dds(int node)
{
  if(dp[node]!=-1)return dp[node];
  dp[node]=sz[node];int now=1e9;
  for(auto x:adj[node])
    now=min(now,dds(x));
  if(now==1e9)now=0;
  dp[node]+=now;return dp[node];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,h;cin>>n>>m>>h;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    rl[u].push_back(v);
    rl[v].push_back(u);
  }
  for(int i=1;i<=n;i++)
  {
    sort(rl[i].begin(),rl[i].end());
    rl[i].erase(unique(rl[i].begin(),rl[i].end()),rl[i].end());
    for(auto j:rl[i])
    {
      if((aa[i]+1)%h!=aa[j])continue;
      adj[i].push_back(j);//cout<<i<<" --> "<<j<<endl;
      rv[j].push_back(i);
    }
  }
  solve(n);vector<pair<int,int> >ed;
  for(int i=1;i<=n;i++)
  {
    for(auto j:adj[i])
    {
      if(con[i]!=con[j])
        ed.push_back({con[i],con[j]});
    }
  }
  sort(ed.begin(),ed.end());
  ed.erase(unique(ed.begin(),ed.end()),ed.end());
   for(int i=1;i<=n;i++)adj[i].clear();
  for(auto x:ed)
    adj[x.first].push_back(x.second);
   memset(vis,0,sizeof vis);
  memset(dp,-1,sizeof(dp));
  int mn=1e9,rt=-1;
  for(int i=1;i<=n;i++)
  {
    if(vis[con[i]])continue;
    int now=dds(con[i]);
    if(now<mn)mn=now,rt=con[i];
    vis[con[i]]=1;
  }
  cout<<mn<<endl;
  while(true)
  {
    for(auto x:str[rt])cout<<x<<" ";
    if(adj[rt].size()==0)break;
     for(auto x:adj[rt])
    {
      if(dp[x]+sz[rt]==dp[rt]){rt=x;break;}
    }
  }
  cout<<endl;
  return 0;
}