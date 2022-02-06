/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/29/2019 18:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 27600 KB                             
*  problem: https://codeforces.com/contest/653/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
const double eps=1e-10;
struct edge
{
  long a,b,f,c;
};
long sr,sn;
vector<edge>ed;
vector<long>adj[N+2];
void clear(void)
{
  ed.clear();
  for(long i=0;i<=sn;i++)
    adj[i].clear();
}
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
      if(dis[v]==inf&&ed[x].f<ed[x].c)
        dis[v]=dis[u]+1,q.push(v);
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
      ed[id].f+=pushed;ed[id^1].f-=pushed;
      return pushed;
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
    while(long pushed=dfs(sr,inf))
      flow+=pushed;
  }
  return flow;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m,k;cin>>n>>m>>k;vector<vector<long> >ed(m);
  for(long i=0;i<m;i++)
  {
    ed[i].resize(3);
    cin>>ed[i][0]>>ed[i][1]>>ed[i][2];
  }
  sr=1,sn=n;int lop=100;
  double lo=0,hi=1e12,md;
  while(lop--)
  {
    md=(lo+hi)/2.0;
    for(auto x:ed)addEdge(x[0],x[1],min((x[2]*1.0)/md,1e12));
    if(dinic()>=k)lo=md;else hi=md;
    clear();
  }
  cout<<setprecision(6)<<fixed<<md*k<<endl;
  return 0;
}