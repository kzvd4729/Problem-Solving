/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2019 11:04                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 265 ms                                          memory_used: 77500 KB                             
*  problem: https://codeforces.com/contest/1187/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int fr[N+2],sr,sn;
vector<int>gr[N+2];
 const int inf=1e9;
struct edge
{
  int a,b,f,c,d;
};
vector<edge>ed;
vector<int>adj[N+2];
void addEdge(int a,int b,int c,int d)
{
  edge e;e={a,b,0,c,d};
  adj[a].push_back(ed.size());
  ed.push_back(e);
   e={b,a,0,0,-d};
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
int dis[N+2],inq[N+2],mnf[N+2],pth[N+2];
pair<int,int>spfa(int n)
{
  for(int i=0;i<=n;i++)dis[i]=inf;
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
pair<int,int>mcmf(int n)
{
  int flow=0,cost=0;
  while(true)
  {
    pair<int,int>p=spfa(n);
    if(!p.first)return {flow,cost};
    flow+=p.first,cost+=p.second;
  }
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k,c,d;cin>>n>>m>>k>>c>>d;
  for(int i=1;i<=k;i++)
  {
    int x;cin>>x;fr[x]++;
  }
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  sr=0,sn=100*n+n+1;
  for(int tm=0;tm<=99;tm++)
  {
    for(int i=1;i<=n;i++)
    {
      addEdge(n*tm+i,n*(tm+1)+i,k,0);
      for(auto x:gr[i])
      {
        for(int cp=1;cp<=k;cp++)
        {
          addEdge(n*tm+i,n*(tm+1)+x,cp,d*cp*cp);
        }
      }
    }
  }
  for(int i=1;i<=n;i++)
    if(fr[i])addEdge(sr,i,fr[i],0);
  for(int tm=0;tm<=100;tm++)
  {
    for(int cp=1;cp<=k;cp++)
    {
      addEdge(n*tm+1,sn,cp,c*tm);
    }
  }
  //addEdge(n+1,sn,k,1);
  cout<<mcmf(sn).second<<endl;
  return 0;
}