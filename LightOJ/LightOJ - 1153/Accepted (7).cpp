/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-09-09 22:46:13                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 8                                          memory_used (MB): 2.7                             
*  problem: https://vjudge.net/problem/LightOJ-1153
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;

struct flow
{
  int sr,sn;//sr=0,sn=last u+1;
  struct edge
  {
    int a,b,f,c;
  };
  vector<edge>ed;
  vector<int>dis,pt;
  vector<vector<int> >adj;
  void clean(void)
  {
    adj.resize(sn+1),dis.resize(sn+1);
    pt.resize(sn+1);ed.clear();
    for(int i=0;i<=sn;i++)
      adj[i].clear();
  }
  void addEdge(int a,int b,int c)
  {
    edge e;e={a,b,0,c};
    adj[a].push_back(ed.size());
    ed.push_back(e);//e={b,a,0,0};
    e={b,a,0,c};//for bidirectional
    adj[b].push_back(ed.size());
    ed.push_back(e);
  }
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
}fl;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    int n;scanf("%d",&n);
    fl.sr=0,fl.sn=n+1;fl.clean();
    int sr,sn,m;scanf("%d%d%d",&sr,&sn,&m);
    int a,b,c;
    for(int i=1;i<=m;i++)
    {
      scanf("%d%d%d",&a,&b,&c);
      if(a==sr)a=0;if(b==sr)b=0;
      if(a==sn)a=n+1;if(b==sn)b=n+1;
      fl.addEdge(a,b,c);
    }
    printf("Case %d: %d\n",++tc,fl.dinic());
  }
  return 0;
}