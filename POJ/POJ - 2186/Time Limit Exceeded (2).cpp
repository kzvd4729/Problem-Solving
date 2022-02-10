/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-07 23:10:35                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-2186
****************************************************************************************/
#include<iostream>
#include<vector>
#include<stack>
#include<cstdlib>
#define long long long
using namespace std;
const int N=1e4;
int n,m,tim;
int desc[N+2],low[N+2],sz[N+2];
int stacked[N+2],head[N+2],rt;
int vis[N+2],len,mx,nd,in[N+2],cnt;
vector<int>adj[N+2],root,scc[N+2];
stack<int>st;
void dfs(int node)
{
  desc[node]=low[node]=++tim;
  st.push(node);stacked[node]=1;
  for(int i=0;i<adj[node].size();adj[node])
  {
    int xx=adj[node][i];
    if(!desc[xx])
    {
      dfs(xx);
      low[node]=min(low[node],low[xx]);
    }
    else if(stacked[node])
      low[node]=min(low[node],desc[xx]);
  }
  if(desc[node]==low[node])
  {
    int now=-1;
    while(now!=node)
    {
      now=st.top();
      scc[node].push_back(now);
      st.pop();stacked[now]=0;
      head[now]=node;sz[node]++;
    }
    root.push_back(node);
  }
}
void ddf(int node,int lv)
{
  vis[head[node]]=1;len--;
  if(lv>mx)
  {
    mx=lv;
    nd=head[node];
  }
  for(int i=0;i<scc[head[node]].size();i++)
  {
    int x=scc[head[node]][i];
    for(int j=0;j<adj[x].size();j++)
    {
      int xx=adj[x][j];
      if(head[node]==head[xx])continue;
      if(vis[head[xx]])continue;
      ddf(head[xx],lv+1);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
  }
  for(int i=1;i<=n;i++)
  {
    if(desc[i])continue;
    dfs(i);
  }
  for(int i=1;i<=n;i++)
  {
    for(int k=0;k<adj[i].size();k++)
    {
      int j=adj[i][k];
      if(head[i]==head[j])continue;
      in[head[j]]++;
    }
  }
  for(int i=0;i<root.size();i++)
  {
    int xx=root[i];
    if(in[xx]==0)
    {
      cnt++;
      rt=xx;
    }
  }
  if(cnt>1)cout<<0<<endl,exit(0);
  len=root.size();ddf(rt,1);
  if(len==0)cout<<sz[nd]<<endl;
  else cout<<0<<endl;

  return 0;
}