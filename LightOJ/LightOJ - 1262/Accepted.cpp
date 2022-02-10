/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-12 18:39:46                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 136                                        memory_used (MB): 3.8                             
*  problem: https://vjudge.net/problem/LightOJ-1262
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
int aa[N+2],bb[N+2];
map<pair<int,int>,pair<int,int> >mp;
map<pair<int,int>,int>ls;

const int inf=1e9;
struct edge
{
  int a,b,f,c;
};
vector<edge>ed;
vector<int>adj[N+2];
void addEdge(int a,int b,int c)
{
  edge e;e={a,b,0,c}; ls[{a,b}]=ed.size();
  //cout<<a<<" --> "<<b<<" "<<c<<"\n";
  adj[a].push_back(ed.size());
  ed.push_back(e);

  e={b,a,0,0};
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
int dis[N+2],sr,sn,pt[N+2];
bool bfs(int n)
{
  for(int i=0;i<=n;i++)dis[i]=inf;
  queue<int>q;q.push(sr);dis[sr]=0;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(int i=0;i<adj[u].size();i++)
    {
      int id=adj[u][i];int v=ed[id].b;
      if(dis[v]==inf&&ed[id].f<ed[id].c)
        dis[v]=dis[u]+1,q.push(v);
    }
  }
  return dis[sn]!=inf;
}
int dfs(int node,int flow)
{
  if(!flow||node==sn)return flow;
  for( ;pt[node]<adj[node].size();pt[node]++)
  {
    int id=adj[node][pt[node]];int v=ed[id].b;
    if(dis[v]!=dis[node]+1)continue;
    if(int pushed=dfs(v,min(flow,ed[id].c-ed[id].f)))
    {
      ed[id].f+=pushed;ed[id^1].f-=pushed;
      return pushed;
    }
  }
  return 0;
}
int dinic(int n)
{
  int flow=0;
  while(bfs(n))
  {
    for(int i=0;i<=n;i++)pt[i]=0;
    while(int pushed=dfs(sr,inf))
      flow+=pushed;
  }
  return flow;
}

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n+m-1;i++)
    {
      cin>>aa[i];
      if(i<=min(n,m))cnt++;
      if(i>max(n,m))cnt--;
      aa[i]-=cnt;
    }
    cnt=0;
    for(int i=1;i<=n+m-1;i++)
    {
      cin>>bb[i];
      if(i<=min(n,m))cnt++;
      if(i>max(n,m))cnt--;
      bb[i]-=cnt;
    }
    int node=n+m-1;mp.clear();ls.clear();
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        addEdge(node+1,node+2,99);
        mp[{i,j}]={node+1,node+2};
        node+=2;
      }
    }
    sr=0,sn=node+n+m;
    for(int i=1;i<=n+m-1;i++)
    {
      int r=min(i,n);++node;
      for(int j=min(m,m-(i-n));j>=1&&r;j--)
      {
        //cout<<r<<" --> "<<j<<"\n";
        addEdge(mp[{r,j}].second,node,99);
        r--;
      }
      //cout<<"\n";
      addEdge(node,sn,bb[i]);
    }
    node=0;
    for(int i=1;i<=n+m-1;i++)
    {
      int r=min(i,n);++node;
      for(int j=max(1,i-n+1);j<=m&&r;j++)
      {
        //cout<<r<<" --> "<<j<<"\n";
        addEdge(node,mp[{r,j}].first,99);
        r--;
      }
      //cout<<"\n";
      addEdge(sr,node,aa[i]);
    }
    dinic(sn);int now=0;
    //for(auto x:ed)
      //cout<<now++<<" "<<x.c<<" "<<x.f<<"\n";
    cout<<"Case "<<++tc<<":"<<"\n";
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        cout<<1+ed[ls[mp[{i,j}]]].f;
        //cout<<ls[rv[{i,j}]];
        if(j!=m)cout<<" ";
      }
      cout<<"\n";
    }
    ed.clear();
    for(int i=0;i<=sn;i++)
      adj[i].clear();
  }
  return 0;
}