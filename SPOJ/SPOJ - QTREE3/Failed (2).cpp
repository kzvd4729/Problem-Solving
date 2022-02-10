/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-02 13:36:16                      
*  solution_verdict: Failed                                  language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-QTREE3
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int n,sz[N+2],level[N+2];
int parent[N+2],chain,pos[N+2];
int chainno[N+2],head[N+2],po;
int seg[5*N+2],q,sp[20][N+2];
vector<int>adj[N+2];
void upd(int node,int lo,int hi,int id)
{
  if(lo==hi)
  {
    seg[node]=seg[node]^1;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id);
  else upd(node*2+1,md+1,hi,id);
  seg[node]=seg[node*2]+seg[node*2+1];
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(rt<lt)swap(lt,rt);
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  int p1=query(node*2,lo,md,lt,rt);
  int p2=query(node*2+1,md+1,hi,lt,rt);
  return p1+p2;
}
void dfs(int node,int par,int h)
{
  sz[node]=1;
  level[node]=h;
  parent[node]=par;
  for(auto xx:adj[node])
  {
    if(xx==par)continue;
    dfs(xx,node,h+1);
    sz[node]+=sz[xx];
  }
}
void hld(int node,int par,int f)
{
  if(f)
  {
    chain++;
    head[chain]=node;
  }
  chainno[node]=chain;
  pos[node]=++po;

  int mx=-1,spc=-1;
  for(auto xx:adj[node])
  {
    if(xx==par)continue;
    if(sz[xx]>mx)
      mx=sz[xx],spc=xx;
  }
  if(spc!=-1)hld(spc,node,0);
  for(auto xx:adj[node])
  {
    if(xx==par||xx==spc)continue;
    hld(xx,node,1);
  }
}
void sparse(void)
{
  memset(sp,-1,sizeof(sp));
  for(int i=1;i<=n;i++)
    sp[0][i]=parent[i];
  for(int j=1;j<=18;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(sp[j-1][i]==-1)continue;
      sp[j][i]=sp[j-1][sp[j-1][i]];
    }
  }
}
int hld_query(int u,int v)
{
  int sum=0;
  while(chainno[u]!=chainno[v])
  {
    if(level[u]<level[v])swap(u,v);
    int x=head[chainno[u]];
    sum+=query(1,1,n,pos[x],pos[u]);
    u=parent[x];
  }
  if(level[u]<level[v])swap(u,v);
  sum+=query(1,1,n,pos[v],pos[u]);
  return sum;
}
void solve(int u,int lc)
{
  if(hld_query(u,u))
  {
    printf("%d\n",u);
    return ;
  }
  for(int i=18;i>=0;i--)
  {
    if(sp[i][u]==-1)continue;
    if(!hld_query(u,sp[i][u]))
      u=sp[i][u];
  }
  printf("%d\n",parent[u]);
}
int main()
{
  while(scanf("%d%d",&n,&q)==2)
  {
    for(int i=1;i<=n;i++)
      adj[i].clear();
    for(int i=2;i<=n;i++)
    {
      int u,v;scanf("%d%d",&u,&v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    memset(seg,0,sizeof(seg));
    chain=0,po=0;
    dfs(1,-1,1);
    hld(1,-1,1);
    sparse();

    while(q--)
    {
      int ty,nd;scanf("%d%d",&ty,&nd);
      if(!ty)upd(1,1,n,pos[nd]);
      else solve(nd,1);
    }
  }
  return 0;
}