/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/09/2020 21:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 23400 KB                             
*  problem: https://codeforces.com/contest/628/problem/F
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
struct edge
{
  int a,b,f,c;
};
int sr,sn;//sr=0,sn=last node+1;
vector<edge>ed;vector<int>adj[N+2];
void clear(void)
{
  ed.clear();
  for(int i=0;i<=sn;i++)adj[i].clear();
}
void addEdge(int a,int b,int c)
{
  edge e;e={a,b,0,c};
  adj[a].push_back(ed.size());
  ed.push_back(e);e={b,a,0,0};
  //e={b,a,0,c};//for bidirectional
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
//finding all possible path. normal bfs
int dis[N+2],pt[N+2];
bool bfs(void)
{
  for(int i=0;i<=sn;i++)dis[i]=inf;
  queue<int>q;q.push(sr);dis[sr]=0;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(auto x:adj[u])
    {
      int v=ed[x].b;
      if(dis[v]==inf&&ed[x].f<ed[x].c)dis[v]=dis[u]+1,q.push(v);
    }
  }
  return dis[sn]!=inf;
}
int dfs(int u,int flow)
{
  if(!flow||u==sn)return flow;
  //if there was not possible before, it is not possible now.
  for( ;pt[u]<adj[u].size();pt[u]++)
  {
    int id=adj[u][pt[u]];int v=ed[id].b;
    if(dis[v]!=dis[u]+1)continue;
    if(int pushed=dfs(v,min(flow,ed[id].c-ed[id].f)))
    {
      ed[id].f+=pushed;ed[id^1].f-=pushed;return pushed;
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
    while(int pushed=dfs(sr,inf))flow+=pushed;
  }
  return flow;
}
void no(){cout<<"unfair"<<endl,exit(0);}
int fr[5+2],q;
void add(int l,int r,int nm)
{
  memset(fr,0,sizeof fr);
  for(int i=l;i<=r;i++)fr[i%5]++;
   for(int i=0;i<5;i++)addEdge(nm,q+2+i,fr[i]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,b;cin>>n>>b>>q;
  vector<pair<int,int> >v(q);
  for(int i=1;i<=q;i++)
    cin>>v[i-1].first>>v[i-1].second;
  sort(v.begin(),v.end());
   int ls=0;sr=0,sn=q+7;int tt=0;
  for(int i=0;i<v.size();i++)
  {
    pair<int,int>x=v[i];x.second-=tt;if(x.second<0)no();
    addEdge(sr,i+1,x.second);tt+=x.second;
    add(ls+1,x.first,i+1);
    ls=x.first;
  }
  if(tt>n)no();
  addEdge(sr,q+1,n-tt);
  add(ls+1,b,q+1);
   for(int i=q+2;i<q+7;i++)addEdge(i,sn,n/5);
   if(dinic()==n)cout<<"fair\n";
  else no();
   return 0;
}