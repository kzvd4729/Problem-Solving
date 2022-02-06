/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/25/2018 22:36                        
*  solution_verdict: Runtime error on test 5                 language: GNU C++14                               
*  run_time: 154 ms                                          memory_used: 152900 KB                            
*  problem: https://codeforces.com/contest/226/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,rt,lev[N+2],parent[N+2],sz[N+2],root[N+2],q;
int anc[N+2],tim,ent[N+2],lin[N+2],nw,sp[40][N+N+N+2],atc[N+2];
vector<int>adj[N+2];
struct persistent
{
  int l,r,sm;
}seg[80*N+2];
void dfs(int node,int par,int lv)
{
  sz[node]=1;lev[node]=lv;parent[node]=par;
  for(auto &x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,lv+1);sz[node]+=sz[x];
    if(sz[x]>=sz[adj[node][0]])swap(x,adj[node][0]);
  }
}
void hld(int node,int par)
{
  ent[node]=++tim;lin[tim]=node;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(x==adj[node][0])anc[x]=anc[node];
    else anc[x]=x;hld(x,node);
  }
}
void upd(int node,int lo,int hi,int pnode,int id)
{
  int md=(lo+hi)/2;
  if(lo==hi)
  {
    seg[node].sm=seg[pnode].sm+1;
    return ;
  }
  if(id<=md)
  {
    seg[node].l=++nw;
    upd(seg[node].l,lo,md,seg[pnode].l,id);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    seg[node].r=++nw;
    upd(seg[node].r,md+1,hi,seg[pnode].r,id);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
int qry(int node,int lo,int hi,int lt,int rt)
{
  int md=(lo+hi)/2;
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node].sm;
  int p1=qry(seg[node].l,lo,md,lt,rt);
  int p2=qry(seg[node].r,md+1,hi,lt,rt);
  return p1+p2;
}
void build(void)
{
  memset(sp,-1,sizeof(sp));
  for(int i=1;i<=n;i++)sp[i][0]=i;
  for(int i=1;i<=n;i++)sp[i][1]=parent[i];
  for(int j=2;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(sp[i][j-1]==-1)continue;
      sp[i][j]=sp[sp[i][j-1]][j-1];
    }
  }
}
int lca(int u,int v)
{
  if(lev[u]<lev[v])swap(u,v);
  for(int i=20;i>=0;i--)
  {
    if(sp[u][i]==-1)continue;
    if(lev[sp[u][i]]>=lev[v])u=sp[u][i];
  }
  if(u==v)return u;
  for(int i=20;i>=0;i--)
  {
    if(sp[u][i]==-1||sp[v][i]==-1)continue;
    if(sp[u][i]==sp[v][i])continue;
    u=sp[u][i];v=sp[v][i];
  }
  return parent[u];
}
int how_much(int u,int v,int y,int r)
{
  int ret=0;
  while(anc[u]!=anc[v])
  {
    ret+=ent[u]-ent[anc[u]]+1;
    ret-=qry(root[r],1,q,ent[anc[u]],ent[u]);
    ret+=qry(root[y],1,q,ent[anc[u]],ent[u]);
    u=parent[anc[u]];
  }
  ret+=ent[u]-ent[v]+1;
  ret-=qry(root[r],1,q,ent[v],ent[u]);
  ret+=qry(root[y],1,q,ent[v],ent[u]);
  return ret;
}
void raise(int &u,int &v,int lc)
{
  int uu=u,vv=v;
  if(lev[uu]>lev[lc])uu=parent[uu];
  if(lev[vv]>lev[lc])vv=parent[vv];
  if(u==lc)
  {
    for(int i=20;i>=0;i--)
    {
      if(sp[v][i]==-1)continue;
      if(lev[sp[v][i]]>lev[lc])v=sp[v][i];
    }
    u=v;v=vv;return ;
  }
  else if(v==lc)
  {
    for(int i=20;i>=0;i--)
    {
      if(sp[u][i]==-1)continue;
      if(lev[sp[u][i]]>lev[lc])u=sp[u][i];
    }
    v=u;u=uu;return ;
  }
  u=uu,v=vv;
}
int finaly(int u,int v,int k,int y,int r)
{
  if(parent[u]==v||parent[v]==u)return -1;
  int lc=lca(u,v);raise(u,v,lc);
  lc=lca(u,v);
  int h=how_much(u,lc,y,r);
  int all=how_much(u,lc,y,r)+how_much(v,lc,y,r);
  if(atc[lc]<=y)all--;if(all<k)return -1;
  if(h>=k)
  {
    for(int i=20;i>=0;i--)
    {
      if(sp[u][i]==-1)continue;
      if(lev[sp[u][i]]<lev[lc])continue;
      int x=how_much(u,sp[u][i],y,r);
      if(x<k)
      {
        k-=x;u=parent[sp[u][i]];
      }
    }
    return u;
  }
  else
  {
    k-=h;u=v;
    for(int i=20;i>=0;i--)
    {
      if(sp[u][i]==-1)continue;
      if(lev[sp[u][i]]<lev[lc])continue;
      int x=how_much(sp[u][i],lc,y,r);if(atc[lc]<=y)x--;
      if(x>=k)u=sp[u][i];
    }
    return u;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;atc[i]=0;
    if(!x)
    {
      rt=i;continue;
    }
    adj[i].push_back(x);adj[x].push_back(i);
  }
  dfs(rt,-1,0);anc[rt]=rt;hld(rt,-1);build();
  cin>>q;
  for(int i=1;i<=q;i++)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int x;cin>>x;root[i]=++nw;atc[x]=i;
      upd(root[i],1,q,root[i-1],ent[x]);
    }
    else
    {
      root[i]=root[i-1];
      int a,b,k,y;cin>>a>>b>>k>>y;
      cout<<finaly(a,b,k,y,i)<<"\n";
    }
  }
  return 0;
}