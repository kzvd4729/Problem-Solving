/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-30 20:40:27                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 70                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11324
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int desc[N+2],low[N+2],head[N+2],stacked[N+2];
int tim,n,m,scc,t,szz[N+2],dp[N+2];
vector<int>adj[N+2],dir[N+2],root,_head[N+2];
stack<int>st;
void tarjan(int node)
{
  desc[node]=low[node]=++tim;
  st.push(node);
  stacked[node]=1;
  for(auto x:adj[node])
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
    scc++;
    root.push_back(node);
    int now=-1,sz=0;
    while(now!=node)
    {
      now=st.top();
      st.pop();
      stacked[now]=0;
      head[now]=node;
      sz++;
      _head[node].push_back(now);
    }
    szz[node]=sz;
  }
}
void dfs(int node)
{
  if(dp[node])return ;
  dp[node]=szz[node];
  int here=0;
  for(auto x:dir[node])
  {
    dfs(x);
    here=max(here,dp[x]);
  }
  dp[node]+=here;
}
int main()
{
  //ofstream cout("out.txt");
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      adj[i].clear();
      _head[i].clear();
      dir[i].clear();
    }
    root.clear();
    memset(desc,0,sizeof(desc));
    for(int i=1;i<=m;i++)
    {
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
    }
    scc=0,tim=0;
    for(int i=1;i<=n;i++)
    {
      if(desc[i])continue;
      tarjan(i);
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=0;j<adj[i].size();j++)
      {
        int x=adj[i][j];
        if(head[i]==head[x])continue;
        dir[head[i]].push_back(head[x]);
      }
    }
    memset(dp,0,sizeof(dp));
    for(int i=0;i<root.size();i++)
    {
      int x=root[i];
      if(dp[x])continue;
      dfs(x);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
      ans=max(ans,dp[i]);
    cout<<ans<<endl;
  }
  return 0;
}