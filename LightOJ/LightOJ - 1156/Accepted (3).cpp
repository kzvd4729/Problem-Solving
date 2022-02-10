/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-28 01:26:55                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 252                                        memory_used (MB): 2.2                             
*  problem: https://vjudge.net/problem/LightOJ-1156
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=2e9;
const int N=1e2;
int t,tc,d,ln,n,sz;
int source,sink,dis[4*N],pt[4*N];
string s;
vector<int>adj[4*N];
struct data
{
  int ds,ty;
  int in,out;
}arr[N+2];
struct edge
{
  int a,b,f,c;
};
vector<edge>ed;
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
void make_graph(int dist)
{
  for(int i=0;i<=sz;i++)
    adj[i].clear();
  ed.clear();
  for(int i=1;i<n;i++)
    add_edge(arr[i].in,arr[i].out,arr[i].ty);
  for(int i=0;i<=n;i++)
    for(int j=i+1;j<=n;j++)
      if(arr[j].ds-arr[i].ds<=dist)
        add_edge(arr[i].out,arr[j].in,2);
}
int solve(void)
{
  source=0;
  sink=++sz;
  arr[source].ds=0,arr[source].in=source,arr[source].out=source,arr[source].ty=2;
  n++;
  arr[n].ds=ln,arr[n].in=sink,arr[n].out=sink,arr[n].ty=2;
  int lo=0,hi=2e9,md;
  while(hi-lo>2)
  {
    int md=(lo+hi)/2;
    make_graph(md);
    if(dinic()>=2)hi=md;
    else lo=md;
  }
  for(int md=lo;md<=hi;md++)
  {
    make_graph(md);
    if(dinic()>=2)
      return md;
  }
  return -1;
}
int main()
{
  //ofstream cout("out.txt");
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>ln;
    sz=0;
    for(int i=1;i<=n;i++)
    {
      cin>>s;
      d=0;
      for(int i=2;i<s.size();i++)
        d=d*10+s[i]-'0';
      if(s[0]=='B')arr[i].ty=2;
      else arr[i].ty=1;
      //cout<<"           "<<c<<endl;
      arr[i].ds=d;
      arr[i].in=++sz;
      arr[i].out=++sz;
    }
    cout<<"Case "<<++tc<<": "<<solve()<<endl;
  }
  return 0;
}