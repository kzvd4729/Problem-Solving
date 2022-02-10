/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-20 20:59:57                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 371                                        memory_used (MB): 6.5                             
*  problem: https://vjudge.net/problem/LightOJ-1404
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;


struct edge
{
  int a,b,f,c,d;
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
void addEdge(int a,int b,int c,int d)
{
  edge e;e={a,b,0,c,d};
  adj[a].push_back(ed.size());
  ed.push_back(e);e={b,a,0,0,-d};
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
int dis[N+2],inq[N+2],mnf[N+2],pth[N+2];
pair<int,int>spfa(void)
{
  for(int i=0;i<=sn;i++)dis[i]=inf;
  queue<int>q;q.push(sr);
  dis[sr]=0,inq[sr]=1,mnf[sr]=inf;
  while(!q.empty())
  {
    int u=q.front();q.pop();inq[u]=0;
    for(auto id:adj[u])
    {
      int v=ed[id].b;
      if(ed[id].c>ed[id].f&&dis[v]>dis[u]+ed[id].d)
      {
        dis[v]=dis[u]+ed[id].d,pth[v]=id;
        mnf[v]=min(mnf[u],ed[id].c-ed[id].f);
        if(!inq[v])q.push(v),inq[v]=1;
      }
    }
  }
  if(dis[sn]==inf)return {0,0};
  int v=sn;
  while(v!=sr)
  {
    int id=pth[v];
    ed[id].f+=mnf[sn],ed[id^1].f-=mnf[sn];
    v=ed[id].a;
  }
  return {mnf[sn],dis[sn]*mnf[sn]};
}
pair<int,int>mcmf(void)
{
  int flow=0,cost=0;
  while(true)
  {
    pair<int,int>p=spfa();
    if(!p.first)return {flow,cost};
    flow+=p.first,cost+=p.second;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n,m,p;cin>>n>>m>>p;
    while(m--)
    {
      int a,b,c,d;cin>>a>>b>>c>>d;
      addEdge(a,b,c,d);
      addEdge(b,a,c,d);
    }
    sn=n+1;
    addEdge(sr,1,p,0);addEdge(n,sn,p,0);
    pair<int,int>pp=mcmf();clear();
    cout<<"Case "<<++tc<<": ";
    if(pp.first!=p)cout<<"impossible\n";
    else cout<<pp.second<<"\n";
  }
  
  return 0;
}