/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-26 15:59:30                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 120                                        memory_used (MB): 17.4                            
*  problem: https://vjudge.net/problem/SPOJ-FASTFLOW
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=5e3;
const long inf=2e9;
long s,t,a,b,c,n,m;
long d[N+2],pt[N+2];
struct edge
{
  long a,b,c,f;
};
vector<edge>e;
vector<long>g[N+2];
void add_edge(long a,long b,long c)
{
  edge e1={a,b,c,0};
  edge e2={b,a,c,0};
  g[a].push_back(e.size());
  e.push_back(e1);
  g[b].push_back(e.size());
  e.push_back(e2);
}
bool bfs()
{
  queue<long>q;
  for(long i=0;i<=N;i++)d[i]=inf;
  d[s]=0;
  q.push(s);
  while(q.size())
  {
    long u=q.front();
    q.pop();
    for(long i=0;i<g[u].size();i++)
    {
      long id=g[u][i];
      long to=e[id].b;
      if(d[to]==inf&&e[id].f<e[id].c)
      {
        q.push(to);
        d[to]=d[u]+1;
      }
    }
  }
  return d[t]!=inf;
}
long dfs(long v,long flow)
{
  if(!flow)return 0;
  if(v==t)return flow;
  for(pt[v];pt[v]<g[v].size();pt[v]++)
  {
    long id=g[v][pt[v]];
    long to=e[id].b;
    if(d[to]!=d[v]+1)continue;
    long pushed=dfs(to,min(flow,e[id].c-e[id].f));
    if(pushed)
    {
      e[id].f+=pushed;
      e[id^1].f-=pushed;
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
    while(long pushed=dfs(s,inf))
      flow+=pushed;
  }
  return flow;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;
  for(long i=1;i<=m;i++)
  {
    cin>>a>>b>>c;
    add_edge(a,b,c);
  }
  s=1,t=n;
  cout<<dinic()<<endl;
  return 0;
}