/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-01 23:02:29                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 380                                        memory_used (MB): 17.4                            
*  problem: https://vjudge.net/problem/SPOJ-QTREE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
int t,n,u,v,w,sz[N+2],parent[N+2],chain,chainno[N+2],level[N+2];
int head[N+2],pos[N+2],po,seg[4*N],sp[17][N+2],id,vl,uu,vv;
vector<pair<int,int> >adj[N+2];
pair<int,int>pr[N+2];
char s[10];
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
  seg[node]=max(seg[node*2],seg[node*2+1]);
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return max(query(node*2,lo,md,lt,rt),query(node*2+1,md+1,hi,lt,rt));
}
int dfs(int node,int pre,int hg)
{
  sz[node]=1;
  parent[node]=pre;
  level[node]=hg;
  for(auto x:adj[node])
  {
    if(x.first==pre)continue;
    sz[node]+=dfs(x.first,node,hg+1);
  }
  return sz[node];
}
void hld(int node,int pre,int f,int cost)
{
  if(f)
  {
    chain++;
    head[chain]=node;
  }
  chainno[node]=chain;
  pos[node]=++po;
  upd(1,1,n,pos[node],cost);
  int mx=0,nd=0,cst;
  for(auto x:adj[node])
  {
    if(x.first==pre)continue;
    if(sz[x.first]>mx)
    {
      mx=sz[x.first];
      nd=x.first;
      cst=x.second;
    }
  }
  if(nd)hld(nd,node,0,cst);
  for(auto x:adj[node])
  {
    if(x.first==pre||x.first==nd)continue;
    hld(x.first,node,1,x.second);
  }
}
void sparse_table(void)
{
  memset(sp,-1,sizeof(sp));
  for(int i=1;i<=n;i++)
    sp[0][i]=parent[i];
  for(int j=1;j<=16;j++)
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
  int ret=0;
  while(u!=parent[v])
  {
    if(chainno[u]==chainno[v])
    {
      ret=max(ret,query(1,1,n,min(pos[u],pos[v]),max(pos[u],pos[v])));
      break;
    }
    else
    {
      ret=max(ret,query(1,1,n,min(pos[u],pos[head[chainno[u]]]),max(pos[u],pos[head[chainno[u]]])));
      u=parent[head[chainno[u]]];
    }
  }
  return ret;
}
void lca(int u,int v)
{
  if(level[u]<level[v])swap(u,v);
  uu=u,vv=v;
  for(int i=16;i>=0;i--)
  {
    int tmp=sp[i][u];
    if(tmp==-1)continue;
    if(level[tmp]>level[v])
      u=tmp;
  }
  if(parent[u]==v)
  {
    printf("%d\n",hld_query(uu,u));
    return ;
  }
  if(level[u]>level[v])u=parent[u];
  for(int i=16;i>=0;i--)
  {
    if(sp[i][u]==-1||sp[i][v]==-1)continue;
    if(sp[i][u]!=sp[i][v])
    {
      u=sp[i][u];
      v=sp[i][v];
    }
  }
  printf("%d\n",max(hld_query(uu,u),hld_query(vv,v)));
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      adj[i].clear();
    for(int i=1;i<n;i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
      if(u>v)swap(u,v);
      pr[i]={u,v};
    }
    dfs(1,-1,0);
    chain=0,po=0;
    memset(seg,0,sizeof(seg));
    hld(1,-1,1,0);
    sparse_table();
    while(true)
    {
      scanf("%s",s);
      if(s[0]=='D')break;
      if(s[0]=='Q')
      {
        scanf("%d%d",&u,&v);
        lca(u,v);
      }
      else
      {
        scanf("%d%d",&id,&vl);
        u=pr[id].first;
        v=pr[id].second;
        if(level[u]<level[v])swap(u,v);
        upd(1,1,n,pos[u],vl);
      }
    }
  }
  return 0;
}