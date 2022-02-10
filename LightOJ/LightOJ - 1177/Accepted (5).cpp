/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-27 19:02:00                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 12                                         memory_used (MB): 2                               
*  problem: https://vjudge.net/problem/LightOJ-1177
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int inf=1e15;
const int N=100;
int sz,t,tc,n,x,cap[N+2],source,sink;
int pt[N+2],dis[N+2],m;
vector<int>adj[N+2];
struct edge
{
  int a,b,f,c;
};
vector<edge>ed;
void add_edge(int a,int b,int c,int d)
{
  edge e;
  e={a,b,0,c};
  adj[a].push_back(ed.size());
  ed.push_back(e);
  if(d)e={b,a,0,0};
  else e={b,a,0,c};
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
bool bfs(void)
{
  queue<int>q;
  for(int i=1;i<=N;i++)
    dis[i]=inf;
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
      if(dis[v]==inf&&ed[id].c>ed[id].f)
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
  if(flow<=0)return 0;
  if(u==sink)return flow;
  for(pt[u];pt[u]<adj[u].size();pt[u]++)
  {
    int id=adj[u][pt[u]];
    int v=ed[id].b;
    if(dis[v]!=dis[u]+1)continue;
    if(int pushed=dfs(v,min(flow,ed[id].c-ed[id].f)))
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
    cin>>n>>m;
    ed.clear();
    for(int i=0;i<=N;i++)adj[i].clear();
    for(int i=2;i<n;i++)
    {
      cin>>x;
      add_edge(i,n+i,x,1);
    }
    int a,b,c,d;
    for(int i=1;i<=m;i++)
    {
      cin>>a>>b>>c;
      if(a>b)swap(a,b);
      if(a==1)
        add_edge(a,b,c,0);
      else
      {
        add_edge(n+a,b,c,1);
        add_edge(n+b,a,c,1);
      }
    }
    source=1;
    sink=n;
    cout<<"Case "<<++tc<<": "<<dinic()<<endl;
  }
  return 0;
}