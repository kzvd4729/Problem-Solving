/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/11/2019 22:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 36600 KB                             
*  problem: https://codeforces.com/contest/863/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50,inf=1e9,R=1e6;
int vis[N+2][N+2],ent[N+2][N+2],ext[N+2][N+2];
struct edge
{
  int a,b,f,c,d;
};
int sr,sn;//sr=0,sn=last node+1;
vector<edge>ed;
vector<int>adj[R+2];
void addEdge(int a,int b,int c,int d)
{
  edge e;e={a,b,0,c,d};
  adj[a].push_back(ed.size());
  ed.push_back(e);e={b,a,0,0,-d};
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
int dis[R+2],inq[R+2],mnf[R+2],pth[R+2];
//pth stores the min cost path in reverse order
//mnf stores the bottleneck flow of the min cost path.
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,q;cin>>n>>q;
  while(q--)
  {
    int ty,l,r,v;cin>>ty>>l>>r>>v;
    for(int i=l;i<=r;i++)
    {
      if(ty==1)
      {
        for(int j=1;j<v;j++)
          vis[i][j]=1;
      }
      else
      {
        for(int j=v+1;j<=n;j++)
          vis[i][j]=1;
      }
    }
  }
  int nd=0;
  for(int i=1;i<=n;i++)
    addEdge(sr,++nd,1,0);
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      ent[i][j]=++nd;
      ext[i][j]=++nd;
      addEdge(ent[i][j],ext[i][j],1,j*j-((j-1)*(j-1)));
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(vis[i][j])continue;
      for(int k=1;k<=n;k++)
        addEdge(i,ent[j][k],1,0);
    }
  }
  sn=++nd;//cout<<sn<<endl;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      addEdge(ext[i][j],sn,j,0);
  pair<int,int>p=mcmf();
  if(p.first<n)cout<<-1<<endl,exit(0);
  cout<<p.second<<endl;
  return 0;
}