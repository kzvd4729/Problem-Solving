/****************************************************************************************
*  @author: kzvd4729                                         created: May/30/2018 17:48                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 202 ms                                          memory_used: 14800 KB                             
*  problem: https://codeforces.com/contest/505/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int desc[N+2],low[N+2],head[N+2],stacked[N+2];
int szz[N+2],f,cnt,ans,tim,vis[N+2],n,m;
vector<int>adj[N+2],dir[N+2];
stack<int>st;
void dfs(int node)
{
  vis[node]=1;
  cnt++;
  if(szz[head[node]]>1)f=1;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    dfs(x);
  }
}
void tarjan(int node)
{
  desc[node]=low[node]=++tim;
  st.push(node);
  stacked[node]=1;
  for(auto x:dir[node])
  {
    if(!desc[x])
    {
      tarjan(x);
      low[node]=min(low[node],low[x]);
    }
    else if(stacked[x])
      low[node]=min(low[node],low[x]);
  }
  if(desc[node]==low[node])
  {
    int now=-1,sz=0;
    while(now!=node)
    {
      now=st.top();
      st.pop();
      stacked[node]=0;
      head[now]=node;
      sz++;
    }
    szz[node]=sz;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;
    cin>>u>>v;
    dir[u].push_back(v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++)
  {
    if(desc[i])continue;
    tarjan(i);
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    cnt=0,f=0;
    dfs(i);
    if(f==0)ans+=cnt-1;
    else ans+=cnt;
  }
  cout<<ans<<endl;
  return 0;
}