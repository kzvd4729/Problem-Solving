/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-19 14:40:16                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-2396
****************************************************************************************/
#include<iostream>
#include<vector>
#include<queue>
#include<assert.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;

struct edge
{
  long a,b,f,c;
};
long sr,sn;//sr=0,sn=last node+1;
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
    for(long i=0;i<adj[u].size();i++)
    {
      long x=adj[u][i];
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
long aa[N+2],bb[N+2],f,mn[200+2][200+2],mx[200+2][200+2];
void upd(long i,long j,char c,long d)
{
  if(c=='=')
  {
    if(mn[i][j]>d||mx[i][j]<d)f=1;
    mn[i][j]=d;mx[i][j]=d;
  }
  else if(c=='>')
  {
    mn[i][j]=d+1;
    if(mn[i][j]>mx[i][j])f=1;
  }
  else
  {
    mx[i][j]=d-1;
    if(mn[i][j]>mx[i][j])f=1;
  }
}
long rm[200+2][200+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n,m;cin>>n>>m;f=0;
    for(long i=1;i<=n;i++)cin>>aa[i];
    for(long i=1;i<=m;i++)cin>>bb[i];

    long q;cin>>q;
    for(long i=1;i<=n;i++)
    {
      for(long j=1;j<=m;j++)mn[i][j]=0,mx[i][j]=1e9;
    }
    while(q--)
    {
      long a,b,d;char c;cin>>a>>b>>c>>d;
      if(a==0&&b==0)
      {
        for(long i=1;i<=n;i++)
        {
          for(long j=1;j<=m;j++)
            upd(i,j,c,d);
        }
      }
      else if(a==0)
      {
        for(long i=1;i<=n;i++)upd(i,b,c,d);
      }
      else if(b==0)
      {
        for(long j=1;j<=m;j++)upd(a,j,c,d);
      }
      else upd(a,b,c,d);
    }
    long ff=0;
    ff|=f;
    long tsr=2*(n+m)+1,tsn=2*(n+m)+2;
    sr=0,sn=tsn+1;vector<long>zr;
    for(long i=1;i<=n;i++)
    {
      long in=2*i-1,out=2*i;
      zr.push_back(ed.size());
      addEdge(sr,out,aa[i]);addEdge(in,sn,aa[i]);
      addEdge(tsr,in,inf);
    }
    for(long i=1;i<=n;i++)
    {
      for(long j=1;j<=m;j++)
      {
        long in=2*i,out=2*n+2*j-1;rm[i][j]=ed.size();
        addEdge(in,out,mx[i][j]-mn[i][j]);
        zr.push_back(ed.size());
        addEdge(sr,out,mn[i][j]);addEdge(in,sn,mn[i][j]);
      }
    }
    for(long j=1;j<=m;j++)
    {
      long in=2*n+2*j-1,out=2*n+2*j;
      zr.push_back(ed.size());
      addEdge(sr,out,bb[j]);addEdge(in,sn,bb[j]);
      addEdge(out,tsn,inf);
    }
    addEdge(tsn,tsr,inf);
    dinic();
    for(long i=0;i<zr.size();i++)
    {
      long x=zr[i];
      if(ed[x].f!=ed[x].c)ff=1;
    }
    if(ff)
    {
      cout<<"IMPOSSIBLE\n";
    }
    else
    {
      for(long i=1;i<=n;i++)
      {
        for(long j=1;j<=m;j++)
        {
          if(j>1)cout<<" ";
          cout<<mn[i][j]+ed[rm[i][j]].f;
          aa[i]-=(mn[i][j]+ed[rm[i][j]].f);
          bb[j]-=(mn[i][j]+ed[rm[i][j]].f);
        }
        cout<<"\n";
      }
    }
    for(int i=1;i<=n;i++)if(aa[i]!=0)assert(0);
    for(int i=1;i<=m;i++)if(bb[i]!=0)assert(0);
    //cout<<"****"<<t<<"\n";
    if(t)cout<<"\n";clear();
  }
  return 0;
}