/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-19 14:34:40                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-2396
****************************************************************************************/
#include<iostream>
#include<vector>
#include<queue>
#define long long long
using namespace std;
const int N=1e6,inf=1e6;

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
    for(int i=0;i<adj[u].size();i++)
    {
      int x=adj[u][i];
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
int aa[N+2],bb[N+2],f,mn[200+2][200+2],mx[200+2][200+2];
void upd(int i,int j,char c,int d)
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
int rm[200+2][200+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=m;i++)cin>>bb[i];

    int q;cin>>q;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)mn[i][j]=0,mx[i][j]=30000;
    }
    while(q--)
    {
      int a,b,d;char c;cin>>a>>b>>c>>d;
      if(a==0&&b==0)
      {
        for(int i=1;i<=n;i++)
        {
          for(int j=1;j<=m;j++)
            upd(i,j,c,d);
        }
      }
      else if(a==0)
      {
        for(int i=1;i<=n;i++)upd(i,b,c,d);
      }
      else if(b==0)
      {
        for(int j=1;j<=m;j++)upd(a,j,c,d);
      }
      else upd(a,b,c,d);
    }
    int ff=0;
    ff|=f;
    int tsr=2*(n+m)+1,tsn=2*(n+m)+2;
    sr=0,sn=tsn+1;vector<int>zr;
    for(int i=1;i<=n;i++)
    {
      int in=2*i-1,out=2*i;
      zr.push_back(ed.size());
      addEdge(sr,out,aa[i]);addEdge(in,sn,aa[i]);
      addEdge(tsr,in,inf);
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        int in=2*i,out=2*n+2*j-1;rm[i][j]=ed.size();
        addEdge(in,out,mx[i][j]-mn[i][j]);
        zr.push_back(ed.size());
        addEdge(sr,out,mn[i][j]);addEdge(in,sn,mn[i][j]);
      }
    }
    for(int j=1;j<=m;j++)
    {
      int in=2*n+2*j-1,out=2*n+2*j;
      zr.push_back(ed.size());
      addEdge(sr,out,bb[j]);addEdge(in,sn,bb[j]);
      addEdge(out,tsn,inf);
    }
    addEdge(tsn,tsr,inf);
    dinic();
    for(int i=0;i<zr.size();i++)
    {
      int x=zr[i];
      if(ed[x].f!=ed[x].c)ff=1;
    }
    if(ff)
    {
      cout<<"IMPOSSIBLE\n";
    }
    else
    {
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
        {
          if(j>1)cout<<" ";
          cout<<mn[i][j]+ed[rm[i][j]].f;
        }
        cout<<"\n";
      }
    }
    //cout<<"****"<<t<<"\n";
    if(t)cout<<"\n";clear();
  }
  return 0;
}