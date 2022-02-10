/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-13 12:15:21                      
*  solution_verdict: Memory Limit Exceeded                   language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1222
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;

const int inf=1e9;
int dis[N+2],inq[N+2],sr,sn,pth[N+2],mnf[N+2];
struct edge
{
  int a,b,f,c,d;
};
vector<int>adj[N+2];
vector<edge>ed;
void addEdge(int a,int b,int c,int d)
{
  edge e;e={a,b,0,c,d};
  adj[a].push_back(ed.size());
  ed.push_back(e);

  e={b,a,0,0,-d};
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
pair<int,int>spfa(int n)
{
  for(int i=0;i<=n;i++)dis[i]=inf,inq[i]=0;
  queue<int>q;q.push(sr);dis[sr]=0,inq[sr]=1;
  mnf[sr]=inf,pth[sr]=0;
  while(!q.empty())
  {
    int u=q.front();q.pop();inq[u]=0;
    for(int i=0;i<adj[u].size();i++)
    {
      int id=adj[u][i];int v=ed[id].b;
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
  return {mnf[sn],dis[sn]};
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
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;sr=0,sn=n+n+1;
    for(int i=1;i<=n;i++)
      addEdge(sr,i,1,0);
    for(int i=n+1;i<=n+n;i++)
      addEdge(i,sn,1,0);
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        int x;cin>>x;
        addEdge(i,j+n,1,-x);
      }
    }
    pair<int,int>p=mcmf(sn);
    cout<<"Case "<<++tc<<": "<<-p.second<<endl;

    ed.clear();
    for(int i=0;i<=sn;i++)
      adj[i].clear();
  }
  return 0;
}