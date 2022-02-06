/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/29/2019 18:09                        
*  solution_verdict: Wrong answer on test 45                 language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 19800 KB                             
*  problem: https://codeforces.com/contest/653/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
const double eps=1e-9;
struct edge
{
  int a,b,f,c;
};
int sr,sn;
vector<edge>ed;
vector<int>adj[N+2];
void clear(void)
{
  ed.clear();
  for(int i=0;i<=sn;i++)
    adj[i].clear();
}
void addEdge(int a,int b,int c)
{
  edge e;e={a,b,0,c};
  adj[a].push_back(ed.size());
  ed.push_back(e);e={b,a,0,0};
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
int dis[N+2],pt[N+2];
bool bfs(void)
{
  for(int i=0;i<=sn;i++)dis[i]=inf;
  queue<int>q;q.push(sr);dis[sr]=0;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(auto x:adj[u])
    {
      int v=ed[x].b;
      if(dis[v]==inf&&ed[x].f<ed[x].c)
        dis[v]=dis[u]+1,q.push(v);
    }
  }
  return dis[sn]!=inf;
}
int dfs(int u,int flow)
{
  if(!flow||u==sn)return flow;
  for( ;pt[u]<adj[u].size();pt[u]++)
  {
    int id=adj[u][pt[u]];int v=ed[id].b;
    if(dis[v]!=dis[u]+1)continue;
    if(int pushed=dfs(v,min(flow,ed[id].c-ed[id].f)))
    {
      ed[id].f+=pushed;ed[id^1].f-=pushed;
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
    for(int i=0;i<=sn;i++)pt[i]=0;
    while(int pushed=dfs(sr,inf))
      flow+=pushed;
  }
  return flow;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;vector<vector<int> >ed(m);
  for(int i=0;i<m;i++)
  {
    ed[i].resize(3);
    cin>>ed[i][0]>>ed[i][1]>>ed[i][2];
  }
  sr=1,sn=n;
  double lo=0,hi=1e6,md;
  while(hi-lo>eps)
  {
    md=(lo+hi)/2.0;
    for(auto x:ed)addEdge(x[0],x[1],(x[2]*1.0)/md);
    if(dinic()>=k)lo=md;else hi=md;
    clear();
  }
  cout<<setprecision(6)<<fixed<<md*k<<endl;
  return 0;
}