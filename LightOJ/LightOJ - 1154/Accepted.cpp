/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-28 13:48:11                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 344                                        memory_used (MB): 2.8                             
*  problem: https://vjudge.net/problem/LightOJ-1154
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e3;
const int N=1e2;
int sz,dis[N+N+2],pt[N+N+2],source,sink;
int t,tc,n,sum;
vector<int>adj[N+N+2];
double d;
struct edge
{
  int a,b,f,c;
};
struct data
{
  int st,jm,in,out;
  double x,y;
}arr[N+2];
vector<edge>ed,tmp;
double dist(double a,double b,double c,double d)
{
  return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
void add_edge(int a,int b,int c)
{
  edge e;
  e={a,b,0,c};
  adj[a].push_back(ed.size());
  ed.push_back(e);
  e={b,a,0,0};
  adj[b].push_back(ed.size());
  ed.push_back(e);
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>d;
    sum=0,sz=0;
    for(int i=0;i<=N+N;i++)adj[i].clear();
    ed.clear();
    for(int i=1;i<=n;i++)
    {
      cin>>arr[i].x>>arr[i].y>>arr[i].st>>arr[i].jm;
      arr[i].in=++sz;
      arr[i].out=++sz;
      add_edge(arr[i].in,arr[i].out,arr[i].jm);
      sum+=arr[i].st;
    }
    //cout<<sum<<endl;
    source=0;
    for(int i=1;i<=n;i++)
      add_edge(source,arr[i].in,arr[i].st);
    for(int i=1;i<=n;i++)
    {
      for(int j=i+1;j<=n;j++)
      {
        double ds=dist(arr[i].x,arr[i].y,arr[j].x,arr[j].y);
        if(ds<=d)
        {
          add_edge(arr[i].out,arr[j].in,inf);
          add_edge(arr[j].out,arr[i].in,inf);
        }
      }
    }
    int flow,f=0;
    tmp=ed;
    cout<<"Case "<<++tc<<":";
    for(int i=1;i<=n;i++)
    {
      sink=arr[i].in;
      flow=dinic();
      ed=tmp;
      if(sum==flow)
      {
        f=1;
        cout<<" "<<i-1;
      }
      //cout<<i<<" "<<flow<<endl;
    }
    if(!f)cout<<" "<<-1;
    cout<<endl;
  }
  return 0;
}