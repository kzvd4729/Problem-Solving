/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-21 22:30:55                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 127                                        memory_used (MB): 6.4                             
*  problem: https://vjudge.net/problem/LightOJ-1243
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1000,inf=1e9;
int n,ds[N+2][N+2],m;
string mt[N+2];

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

void bfs(char c,int cp)
{
  int x,y;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      ds[i][j]=inf;
      if(mt[i][j]==c)x=i,y=j;
    }
  }
  queue<pair<int,int> >q;
  q.push({x,y});ds[x][y]=0;
  while(q.size())
  {
    int u=q.front().first,v=q.front().second;q.pop();
    int uu,vv;

    uu=u+1,vv=v;
    if(uu>=0&&uu<n&&vv>=0&&vv<n&&mt[uu][vv]!='#')
    {
      if(ds[u][v]+1<ds[uu][vv])
        ds[uu][vv]=ds[u][v]+1,q.push({uu,vv});
    }

    uu=u-1,vv=v;
    if(uu>=0&&uu<n&&vv>=0&&vv<n&&mt[uu][vv]!='#')
    {
      if(ds[u][v]+1<ds[uu][vv])
        ds[uu][vv]=ds[u][v]+1,q.push({uu,vv});
    }

    uu=u,vv=v+1;
    if(uu>=0&&uu<n&&vv>=0&&vv<n&&mt[uu][vv]!='#')
    {
      if(ds[u][v]+1<ds[uu][vv])
        ds[uu][vv]=ds[u][v]+1,q.push({uu,vv});
    }

    uu=u,vv=v-1;
    if(uu>=0&&uu<n&&vv>=0&&vv<n&&mt[uu][vv]!='#')
    {
      if(ds[u][v]+1<ds[uu][vv])
        ds[uu][vv]=ds[u][v]+1,q.push({uu,vv});
    }
  }
  int cnt=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(mt[i][j]!='m')continue;
      ++cnt;
      addEdge(cnt,m+c-'A'+1,1,ds[i][j]);
      //cout<<"**"<<ds[i][j];
    }
  }
} 
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int k;cin>>n>>k>>m;
    for(int i=0;i<n;i++)cin>>mt[i];
    sn=m+k+1;
    for(int i=1;i<=m;i++)addEdge(sr,i,1,0);
    for(int i=0;i<k;i++)
    {
      int x;cin>>x;bfs('A'+i,x);
      addEdge(m+i+1,sn,x,0);
    }
    pair<int,int>p=mcmf();cout<<"Case "<<++tc<<": "<<p.second<<"\n";
    clear();
  }
  return 0;
}