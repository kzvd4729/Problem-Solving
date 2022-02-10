/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-30 21:31:34                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 168                                        memory_used (MB): 15.3                            
*  problem: https://vjudge.net/problem/LightOJ-1417
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e4;
int t,tc,n,tim;
int desc[N+2],low[N+2],parent[N+2],stacked[N+2];
int sz[N+2],dp[N+2];
vector<int>adj[N+2],dir[N+2],root,head[N+2];
stack<int>st;
void tarjan(int node)
{
  desc[node]=low[node]=++tim;
  st.push(node);
  stacked[node]=1;
  for(int i=0;i<dir[node].size();i++)
  {
    int next=dir[node][i];
    if(!desc[next])
    {
      tarjan(next);
      low[node]=min(low[node],low[next]);
    }
    else if(stacked[next])
      low[node]=min(low[node],low[next]);
  }
  if(low[node]==desc[node])
  {
    root.push_back(node);
    int now=-1,here=0;
    while(now!=node)
    {
      now=st.top();
      st.pop();
      stacked[now]=0;
      here++;
      parent[now]=node;
      head[node].push_back(now);
    }
    sz[node]=here;
  }
}
void dfs(int node)
{
  if(dp[node])return ;
  dp[node]=sz[node];
  int here=0;
  for(int i=0;i<adj[node].size();i++)
  {
    int x=adj[node][i];
    here=max(here,dp[x]);
  }
  dp[node]+=here;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
      dir[i].clear();
      adj[i].clear();
      head[i].clear();
      dp[i]=0;
      desc[i]=0;
    }
    tim=0;
    root.clear();
    for(int i=1;i<=n;i++)
    {
      int u,v;
      cin>>u>>v;
      dir[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
      if(desc[i])continue;
      tarjan(i);
    }
//    cout<<"SCC     "<<scc<<endl;
//    for(int i=1;i<=n;i++)
//      cout<<desc[i]<<" "<<low[i]<<endl;
    for(int i=1;i<=n;i++)
    {
      for(int j=0;j<dir[i].size();j++)
      {
        int x=dir[i][j];
        if(parent[i]==parent[x])continue;
        adj[parent[i]].push_back(parent[x]);
      }
    }
    for(int i=0;i<root.size();i++)
    {
      int x=root[i];
      if(dp[x])continue;
      dfs(x);
    }
    int mx=0,pr=n;
    for(int i=0;i<root.size();i++)
    {
      int x=root[i];
      int mn=n;
      for(int j=0;j<head[x].size();j++)
        mn=min(mn,head[x][j]);
      if(dp[x]>mx)
        mx=dp[x],pr=mn;
      else if(dp[x]==mx)
        pr=min(pr,mn);
    }
    //cout<<mx<<endl;
    cout<<"Case "<<++tc<<": "<<pr<<endl;
  }
  return 0;
}