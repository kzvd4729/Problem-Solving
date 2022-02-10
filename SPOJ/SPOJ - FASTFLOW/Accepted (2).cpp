/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-26 16:12:23                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 110                                        memory_used (MB): 16.4                            
*  problem: https://vjudge.net/problem/SPOJ-FASTFLOW
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=2e9;
const int N=5e3;
int n,m,source,sink;
int dis[N+2],pt[N+2];
struct edge
{
  int a,b,f,c;
};
vector<edge>ed;
vector<int>adj[N+2];
void add_edge(int a,int b,int c)
{
  edge e;
  e={a,b,0,c};
  adj[a].push_back(ed.size());
  ed.push_back(e);
  e={b,a,0,c};
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
bool bfs(void)
{
  for(int i=1;i<=n;i++)dis[i]=inf;
  queue<int>q;
  q.push(source);
  dis[source]=0;
  while(q.size())
  {
    int u=q.front();
    q.pop();
    for(int i=0;i<adj[u].size();i++)
    {
      int id=adj[u][i];
      int v=ed[id].b;
      if(dis[v]==inf&&ed[id].f<ed[id].c)
      {
        dis[v]=dis[u]+1;
        q.push(v);
      }
    }
  }
  return dis[sink]!=inf;
}
int dfs(int u,int flow)
{
  if(!flow)return 0;
  if(u==sink)return flow;
  for( ;pt[u]<adj[u].size();pt[u]++)
  {
    int id=adj[u][pt[u]];
    int v=ed[id].b;
    if(dis[v]!=dis[u]+1)continue;
    int pushed=dfs(v,min(flow,ed[id].c-ed[id].f));
    if(pushed)
    {
      ed[id].f+=pushed;
      ed[id^1].f-=pushed;
      return pushed;
    }
  }
  return 0;
}
long dinic()
{
  long flow=0;
  while(bfs())
  {
    memset(pt,0,sizeof(pt));
    while(int pushed=dfs(source,inf))
      flow+=(pushed*1LL);
  }
  return flow;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;
  int a,b,c;
  for(int i=1;i<=m;i++)
  {
    cin>>a>>b>>c;
    add_edge(a,b,c);
  }
  source=1;
  sink=n;
  cout<<dinic()<<endl;
  return 0;
}