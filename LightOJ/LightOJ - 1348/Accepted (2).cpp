/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-01 03:23:48                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1300                                       memory_used (MB): 8.3                             
*  problem: https://vjudge.net/problem/LightOJ-1348
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e4;
int t,tc,n,u,v,nodes[N+2],parent[N+2],level[N+2],sz[N+2];
int chain,chainno[N+2],head[N+2],pos[N+2],po,seg[4*N],sp[17][N+2];
int q,ty;
vector<int>adj[N+2];
int dfs(int node,int pre,int hg)
{
  parent[node]=pre;
  sz[node]=1;
  level[node]=hg;
  for(int i=0;i<adj[node].size();i++)
  {
    if(adj[node][i]==pre)continue;
    sz[node]+=dfs(adj[node][i],node,hg+1);
  }
  return sz[node];
}
void upd(int node,int lo,int hi,int id,int vl)
{
  if(lo==hi)
  {
    seg[node]=vl;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=seg[node*2]+seg[node*2+1];
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return query(node*2,lo,md,lt,rt)+query(node*2+1,md+1,hi,lt,rt);
}
void hld(int node,int pre,int f)
{
  if(f)
  {
    chain++;
    head[chain]=node;
  }
  chainno[node]=chain;
  pos[node]=++po;
  upd(1,1,n,pos[node],nodes[node]);
  int mx=-1,nd=-1;
  for(int i=0;i<adj[node].size();i++)
  {
    if(adj[node][i]==pre)continue;
    if(sz[adj[node][i]]>mx)
    {
      mx=sz[adj[node][i]];
      nd=adj[node][i];
    }
  }
  if(nd!=-1)hld(nd,node,0);
  for(int i=0;i<adj[node].size();i++)
  {
    if(adj[node][i]==pre||adj[node][i]==nd)continue;
    hld(adj[node][i],node,1);
  }
}
void sparse_table(void)
{
  memset(sp,-1,sizeof(sp));
  for(int i=0;i<n;i++)
    sp[0][i]=parent[i];
  for(int j=1;j<=16;j++)
  {
    for(int i=0;i<n;i++)
    {
      if(sp[j-1][i]==-1)continue;
      sp[j][i]=sp[j-1][sp[j-1][i]];
    }
  }
}
int hld_query(int u,int v)
{
  if(level[u]<level[v])swap(u,v);
  int ret=0;
 
  while(true)
  {
    if(chainno[u]==chainno[v])
    {
      ret+=query(1,1,n,min(pos[u],pos[v]),max(pos[u],pos[v]));
      return ret;
    }
    else
    {
      ret+=query(1,1,n,min(pos[u],pos[head[chainno[u]]]),max(pos[u],pos[head[chainno[u]]]));
      u=parent[head[chainno[u]]];
    }
    if(u==-1)return ret;
    if(level[u]<level[v])return ret;
  }
}
void lca(int u,int v)
{
  if(level[u]<level[v])swap(u,v);
  int uu=u,vv=v;
  for(int i=16;i>=0;i--)
  {
    if(sp[i][u]==-1)continue;
    if(level[sp[i][u]]>=level[v])
      u=sp[i][u];
  }
  if(u==v)
  {
    printf("%d\n",hld_query(uu,u));
    return ;
  }
  for(int i=16;i>=0;i--)
  {
    if(sp[i][u]==-1||sp[i][v]==-1)continue;
    if(sp[i][u]==sp[i][v])continue;
    u=sp[i][u];
    v=sp[i][v];
  }
  printf("%d\n",hld_query(uu,parent[u])+hld_query(vv,parent[v])-nodes[parent[u]]);
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      scanf("%d",&nodes[i]);
    for(int i=0;i<n;i++)adj[i].clear();
    memset(seg,0,sizeof(seg));
    for(int i=1;i<n;i++)
    {
      scanf("%d%d",&u,&v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(0,-1,0);
    chain=0,po=0;
    hld(0,-1,1);
    sparse_table();
    scanf("%d",&q);
    printf("Case %d:\n",++tc);
    while(q--)
    {
      int u,v;
      scanf("%d%d%d",&ty,&u,&v);
      if(ty==0)lca(u,v);
      else
      {
        upd(1,1,n,pos[u],v);
        nodes[u]=v;
      }
    }
  }
  return 0;
}