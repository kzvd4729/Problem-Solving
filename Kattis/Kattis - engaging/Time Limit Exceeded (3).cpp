/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-12 19:37:52                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-engaging
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3,inf=1e9;

struct edge
{
  int a,b,f,c,d;
};
int sr,sn;//sr=0,sn=last node+1;
vector<edge>ed;
vector<int>adj[N+2];
void addEdge(int a,int b,int c,int d)
{
  //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
  edge e;e={a,b,0,c,d};
  adj[a].push_back(ed.size());
  ed.push_back(e);e={b,a,0,0,-d};
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
int dis[N+2],inq[N+2],mnf[N+2],pth[N+2],q[N*N+2],top;
pair<int,int>spfa(void)
{
  for(int i=0;i<=sn;i++)dis[i]=inf;
  top=0;q[++top]=sr;
  dis[sr]=0,inq[sr]=1,mnf[sr]=inf;
  for(int ii=1;ii<=top;ii++)
  {
    int u=q[ii];inq[u]=0;
    for(auto id:adj[u])
    {
      int v=ed[id].b;
      if(ed[id].c>ed[id].f&&dis[v]>dis[u]+ed[id].d)
      {
        dis[v]=dis[u]+ed[id].d,pth[v]=id;
        mnf[v]=min(mnf[u],ed[id].c-ed[id].f);
        if(!inq[v])q[++top]=v,inq[v]=1;
      }
    }
  }
  if(dis[sn]==inf)return {0,0};
  int v=sn;
  while(v!=sr)//sending maximum flow through the min cost path
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
int vis[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;scanf("%d%d%d",&m,&n,&k);
  sr=0,sn=n+m+1;
  for(int i=1;i<=k;i++)
  {
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    addEdge(a,n+b,1,-c);
    vis[a][b]=true;
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      if(!vis[i][j])addEdge(i,n+j,1,0);
  }
  for(int i=1;i<=n;i++)addEdge(sr,i,1,0);
  for(int i=1;i<=m;i++)addEdge(n+i,sn,1,0);

  printf("%d\n",-mcmf().second);
  vector<pair<int,int> >v;
  for(int i=1;i<=n;i++)
  {
    for(auto x:adj[i])
    {
      if(ed[x].f==1)
      {
        v.push_back({i,ed[x].b});
        break;
      }
    }
  }
  printf("%d\n",(int)v.size());
  for(auto x:v)
    printf("%d %d\n",x.first,x.second-n);
  return 0;
}