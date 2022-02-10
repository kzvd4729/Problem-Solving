/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-11-19 20:47:24                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 16                                         memory_used (MB): 2.6                             
*  problem: https://vjudge.net/problem/LightOJ-1167
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2+1;
const int inf=1e7;
int n,source,sink,pt[N+2],dis[N+2];
vector<int>adj[N+2];
struct tunnel
{
  int a,b,c;
};
vector<tunnel>tn;
struct edge
{
  int a,b,c,f;
};
vector<edge>ed;
void add_edge(int a,int b,int c,int f)
{
  edge e={a,b,c,f};
  adj[a].push_back(ed.size());
  ed.push_back(e);

  e={b,a,0,0};
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
bool bfs(void)
{
  for(int i=0;i<=N;i++)
    dis[i]=inf;
  queue<int>q;q.push(source);dis[source]=0;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(int i=0;i<adj[u].size();i++)
    {
      int id=adj[u][i];
      if(ed[id].c-ed[id].f>0&&dis[ed[id].b]==inf)
      {
        dis[ed[id].b]=dis[u]+1;
        q.push(ed[id].b);
      }
    }
  }
  return dis[sink]!=inf;
}
int dfs(int u,int flow)
{
  if(u==sink||!flow)return flow;
  for( ;pt[u]<adj[u].size();pt[u]++)
  {
    int id=adj[u][pt[u]];
    if(dis[u]+1!=dis[ed[id].b])continue;
    int here=dfs(ed[id].b,min(flow,ed[id].c-ed[id].f));
    if(here)
    {
      ed[id].f+=here;ed[id^1].f-=here;
      return here;
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
void build_graph(int lm)
{
  ed.clear();for(int i=0;i<=N;i++)adj[i].clear();
  for(int i=0;i<tn.size();i++)
  {
    tunnel x=tn[i];if(x.c>lm)continue;
    if(x.a==source&&x.b==n+1)
      add_edge(source,sink,1,0);
    else if(x.a==source)
      add_edge(source,x.b,1,0);
    else if(x.b==n+1)
      add_edge(x.a+n,sink,1,0);
    else add_edge(x.a+n,x.b,1,0);
  }
  for(int i=1;i<=n;i++)
    add_edge(i,i+n,1,0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int m;cin>>n>>m;
    source=0,sink=n+n+1;tn.clear();
    while(m--)
    {
      int a,b,c;cin>>a>>b>>c;
      if(a>b)swap(a,b);
      tn.push_back({a,b,c});
    }
    int k;cin>>k;
    int lo=0,hi=1e5,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;build_graph(md);
      int kk=dinic();
      if(kk>=k)hi=md;else lo=md;
    }
    for(md=lo;md<=hi;md++)
    {
      build_graph(md);if(dinic()>=k)break;
    }
    if(md>hi)cout<<"Case "<<++tc<<": "<<"no solution"<<endl;
    else cout<<"Case "<<++tc<<": "<<md<<endl;
  }
  return 0;
}