/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/22/2020 00:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/1082/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5,inf=1e9;
struct edge
{
  long a,b,f,c;
};
long sr,sn;//sr=0,sn=last node+1;
vector<edge>ed;vector<long>adj[N+2];
void addEdge(long a,long b,long c)
{
  edge e;e={a,b,0,c};
  adj[a].push_back(ed.size());
  ed.push_back(e);e={b,a,0,0};
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
long dis[N+2],pt[N+2];
bool bfs(void)
{
  for(long i=0;i<=sn;i++)dis[i]=inf;
  queue<long>q;q.push(sr);dis[sr]=0;
  while(q.size())
  {
    long u=q.front();q.pop();
    for(auto x:adj[u])
    {
      long v=ed[x].b;
      if(dis[v]==inf&&ed[x].f<ed[x].c)dis[v]=dis[u]+1,q.push(v);
    }
  }
  return dis[sn]!=inf;
}
long dfs(long u,long flow)
{
  if(!flow||u==sn)return flow;
  for( ;pt[u]<adj[u].size();pt[u]++)
  {
    long id=adj[u][pt[u]];long v=ed[id].b;
    if(dis[v]!=dis[u]+1)continue;
    if(long pushed=dfs(v,min(flow,ed[id].c-ed[id].f)))
    {
      ed[id].f+=pushed;ed[id^1].f-=pushed;return pushed;
    }
  }
  return 0;
}
long dinic(void)
{
  long flow=0;
  while(bfs())
  {
    for(long i=0;i<=sn;i++)pt[i]=0;
    while(long pushed=dfs(sr,inf))flow+=pushed;
  }
  return flow;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m;sn=n+m+1;
  for(long i=1;i<=n;i++)
  {
    long x;cin>>x;addEdge(m+i,sn,x);
  }
  long sm=0;
  for(long i=1;i<=m;i++)
  {
    long u,v,w;cin>>u>>v>>w;sm+=w;
    addEdge(sr,i,w);addEdge(i,m+u,inf);addEdge(i,m+v,inf);
  }
  cout<<sm-dinic()<<endl;
  return 0;
}