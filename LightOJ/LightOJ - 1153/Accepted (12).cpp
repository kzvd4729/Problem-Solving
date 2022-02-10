/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-26 16:30:25                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 12                                         memory_used (MB): 2.4                             
*  problem: https://vjudge.net/problem/LightOJ-1153
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=2e9;
const int N=5e3;
int t,tc,n,m,source,sink;
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
int dinic(void)
{
  int flow=0;
  while(bfs())
  {
    memset(pt,0,sizeof(pt));
    while(int pushed=dfs(source,inf))
      flow+=pushed;
  }
  return flow;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)adj[i].clear();
    ed.clear();
    cin>>source>>sink>>m;
    int a,b,c;
    for(int i=1;i<=m;i++)
    {
      cin>>a>>b>>c;
      add_edge(a,b,c);
    }
    cout<<"Case "<<++tc<<": "<<dinic()<<endl;
  }
  return 0;
}