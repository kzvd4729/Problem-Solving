/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-28 20:45:53                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1405
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
const int inf=1e5;
int pos[N+2][N+2][3],n,m,dis[N*N+2];
int t,tc,sz,pt[N*N+2],source,sink;
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
char mat[N+2][N+2],s[N+2];
vector<int>adj[2*N*N+2];
struct edge
{
  int a,b,f,c;
}e;
vector<edge>ed;
void add_edge(int a,int b,int c)
{
  e={a,b,0,c};
  adj[a].push_back(ed.size());
  ed.push_back(e);
  e={b,a,0,0};
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
void make_graph(void)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      pos[i][j][1]=++sz;
      pos[i][j][2]=++sz;
    }
  }
  source=0;
  sink=++sz;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      add_edge(pos[i][j][1],pos[i][j][2],1);
      if(mat[i][j]=='*')
        add_edge(source,pos[i][j][1],1);
      if(i==1||i==n||j==1||j==m)
        add_edge(pos[i][j][2],sink,1);
      for(int k=0;k<4;k++)
      {
        int ii=i+dr[k];
        int jj=j+dc[k];
        if(ii<1||ii>n||jj<1||jj>m)continue;
        add_edge(pos[i][j][2],pos[ii][jj][1],1);
        add_edge(pos[ii][jj][2],pos[i][j][1],1);
      }
    }
  }
}
bool bfs(void)
{
  queue<int>q;
  for(int i=0;i<=sz;i++)
    dis[i]=inf;
  dis[source]=0;
  q.push(source);
  while(q.size())
  {
    int u=q.front();
    q.pop();
    for(int i=0;i<adj[u].size();i++)
    {
      int id=adj[u][i];
      int v=ed[id].b;
      if(dis[v]==inf&&ed[id].c>ed[id].f)
      {
        dis[v]=dis[u]+1;
        q.push(v);
      }
    }
  }
  return dis[sink]!=inf;
}
bool dfs(int u,int flow)
{
  if(!flow)return 0;
  if(u==sink)return flow;
  for(pt[u];pt[u]<adj[u].size();pt[u]++)
  {
    int id=adj[u][pt[u]];
    int v=ed[id].b;
    if(dis[u]+1!=dis[v])continue;
    if(int pushed=dfs(v,min(flow,ed[id].c-ed[id].f)))
    {
      ed[id].f+=pushed;
      ed[id^1].f-=pushed;
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
    memset(pt,0,sizeof(pt));
    while(int pushed=dfs(source,inf))
      flow+=pushed;
  }
  return flow;
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&n,&m);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
      scanf("%s",s);
      for(int j=1;j<=m;j++)
      {
        mat[i][j]=s[j-1];
        if(mat[i][j]=='*')cnt++;
      }
    }
    make_graph();

    if(cnt==dinic())printf("Case %d: yes\n",++tc);
    else printf("Case %d: no\n",++tc);

    for(int i=0;i<=sz;i++)
      adj[i].clear();
    ed.clear();
    sz=0;
  }
  return 0;
}