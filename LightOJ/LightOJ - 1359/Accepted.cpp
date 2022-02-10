/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-12 23:10:22                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 738                                        memory_used (MB): 48.3                            
*  problem: https://vjudge.net/problem/LightOJ-1359
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int inf=1e9;
int dis[N+2],bad[N+2],sp[N+2][21],vis[N+2];
int lvl[N+2],ent[N+2],ext[N+2],tim;
vector<pair<int,int> >adj[N+2];
vector<int>dir[N+2],parent[N+2],topo,dom[N+2];
void dfs(int node)
{
 vis[node]=1;
 for(auto x:dir[node])
 {
  if(vis[x])continue;
  dfs(x);
 }
 topo.push_back(node);
}
void dfs2(int node)
{
 ent[node]=++tim;
 for(auto x:dom[node])
  dfs2(x);
 ext[node]=tim;
}
int lca(int u,int v)
{
 if(lvl[u]<lvl[v])swap(u,v);
 for(int i=19;i>=0;i--)
 {
  if(sp[u][i]==-1)continue;
  if(lvl[sp[u][i]]>=lvl[v])
   u=sp[u][i];
 }
 if(u==v)return u;
 for(int i=19;i>=0;i--)
 {
  if(sp[u][i]==-1||sp[v][i]==-1)continue;
  if(sp[u][i]==sp[v][i])continue;
  u=sp[u][i];v=sp[v][i];
 }
 return sp[u][0];
}
void upd(int pr,int ch)
{
 sp[ch][0]=pr;
 for(int i=1;i<20;i++)
 {
  if(sp[ch][i-1]==-1)break;
  sp[ch][i]=sp[sp[ch][i-1]][i-1];
 }
 lvl[ch]=lvl[pr]+1;dom[pr].push_back(ch);
}
int main()
{
 int t,tc=0;scanf("%d",&t);
 while(t--)
 {
  int n,m;scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++)
  {
   adj[i].clear(),dir[i].clear();
   parent[i].clear();dom[i].clear();
  }
  vector<pair<int,pair<int,int> > >ed;
  while(m--)
  {
   int u,v,w;scanf("%d%d%d",&u,&v,&w);
   adj[u].push_back({v,w});
   adj[v].push_back({u,w});
   ed.push_back({u,{v,w}});
  }
  set<pair<int,int> >st;st.insert({0,0});
  for(int i=1;i<n;i++)dis[i]=inf;
  while(st.size())
  {
   pair<int,int>p=*st.begin();st.erase(p);
   for(auto x:adj[p.second])
   {
    if(dis[x.first]>dis[p.second]+x.second)
    {
     dis[x.first]=dis[p.second]+x.second;
     st.insert({dis[x.first],x.first});
    }
   }
  }
  memset(bad,0,sizeof(bad));
  for(int i=0;i<n;i++)
   if(dis[i]==inf)bad[i]=1;
  for(auto x:ed)
  {
   int a=x.first,b=x.second.first;
   if(dis[a]>dis[b])swap(a,b);
   if(dis[a]+x.second.second==dis[b])
   {
    dir[a].push_back(b);
    parent[b].push_back(a);
   }
  }
  memset(vis,0,sizeof(vis));topo.clear();
  memset(sp,-1,sizeof(sp));dfs(0);
  reverse(topo.begin(),topo.end());
  if(topo[0])assert(0);
  for(int i=1;i<topo.size();i++)
  {
   int x=topo[i];
   int dm=parent[x][0];
   for(int j=1;j<parent[x].size();j++)
    dm=lca(dm,parent[x][j]);
   upd(dm,x);
  }
  tim=0;dfs2(0);int q;scanf("%d",&q);
  printf("Case %d:\n",++tc);
  while(q--)
  {
   int x;scanf("%d",&x);vector<int>nd;
   while(x--)
   {
    int z;scanf("%d",&z);
    if(!bad[z])nd.push_back(z);
   }
   if(nd.size()==0)printf("0\n");
   else
   {
    int lc=nd[0];
    for(int i=1;i<nd.size();i++)
     lc=lca(lc,nd[i]);
    printf("%d %d\n",lvl[lc]+1,ext[lc]-ent[lc]+1);
   }
  }
 }
 return 0;
}