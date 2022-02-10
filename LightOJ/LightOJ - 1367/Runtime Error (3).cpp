/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-21 18:32:30                      
*  solution_verdict: Runtime Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1367
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4,inf=1e9;

struct edge
{
  int a,b,f,c;
};
int sr,sn;//sr=0,sn=last node+1;
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
  //e={b,a,0,c};//for bidirectional
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

int aa[N+2],bb[N+2],mn[N+2],srad[N+2],snad[N+2];
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);

  int t,tc=0;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;sn=n+1;
    for(int i=1;i<=n;i++)srad[i]=0,snad[i]=0;
    for(int i=1;i<=m;i++)
    {
      int a,b,c,d;cin>>a>>b>>c>>d;
      bb[i]=ed.size();mn[i]=c;
      addEdge(a,b,d-c);
      srad[b]+=c,snad[a]+=c;
      //aa[i]=ed.size();addEdge(sr,b,c);addEdge(a,sn,c);
    }
    addEdge(n,1,inf-1);
    for(int i=1;i<=n;i++)
    {
      aa[i]=ed.size();
      addEdge(sr,i,srad[i]),addEdge(i,sn,snad[i]);
    }
    dinic();int f=0;
    for(int i=1;i<=n;i++)
    {
      if(ed[aa[i]].f!=ed[aa[i]].c)f=1;
    }
    cout<<"Case "<<++tc<<": ";
    if(f)cout<<"no\n";
    else
    {
      cout<<"yes\n";
      for(int i=1;i<=m;i++)
        cout<<mn[i]+ed[bb[i]].f<<"\n";
    }
    clear();
  }
  return 0;
}