/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/02/2018 16:30                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/226/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,root,sz[N+2],level[N+2],parent[N+2];
int chain,chainno[N+2],pos[N+2],po,head[N+2];
int sp[20][N+2],szz,rt[N+2],add[N+2];
vector<int>adj[N+2];
struct segment
{
  int l,r,sum;
}seg[50*N+2];
void upd(int node,int lo,int hi,int pnode,int id)
{
  if(lo==hi)
  {
    seg[node].sum=seg[pnode].sum+1;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)
  {
    if(!seg[node].l)seg[node].l=++szz;
    upd(seg[node].l,lo,md,seg[pnode].l,id);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    if(!seg[node].r)seg[node].r=++szz;
    upd(seg[node].r,md+1,hi,seg[pnode].r,id);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sum=seg[seg[node].l].sum+seg[seg[node].r].sum;
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node].sum;
  int md=(lo+hi)/2;
  int p1=query(seg[node].l,lo,md,lt,rt);
  int p2=query(seg[node].r,md+1,hi,lt,rt);
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
    if(sz[xx]>mx)mx=sz[xx],spc=xx;
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
  for(int j=1;j<=16;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(sp[j-1][i]==-1)continue;
      sp[j][i]=sp[j-1][sp[j-1][i]];
    }
  }
}
int lca(int u,int v)
{
  if(level[u]<level[v])swap(u,v);
  for(int i=18;i>=0;i--)
  {
    if(sp[i][u]==-1)continue;
    if(level[sp[i][u]]>=level[v])
      u=sp[i][u];
  }
  if(u==v)return u;
  for(int i=18;i>=0;i--)
  {
    if(sp[i][u]==-1||sp[i][v]==-1)continue;
    if(sp[i][u]==sp[i][v])continue;
    u=sp[i][u];
    v=sp[i][v];
  }
  return parent[u];
}
int hld_query(int u,int v,int c,int p)
{
  int sum=0;
  while(chainno[u]!=chainno[v])
  {
    if(level[u]<level[v])swap(u,v);
    int x=head[chainno[u]];
    sum+=query(c,1,n,pos[x],pos[u]);
    sum-=query(p,1,n,pos[x],pos[u]);
    u=parent[x];
  }
  if(level[u]<level[v])swap(u,v);
  sum+=query(c,1,n,pos[v],pos[u]);
  sum-=query(p,1,n,pos[v],pos[u]);
  return sum;
}
void solve(int a,int b,int k,int y,int lc,int i)
{
  int u=a,v=b;
  for(int i=18;i>=0;i--)
  {
    if(sp[i][u]==-1)continue;
    if(level[sp[i][u]]<level[lc])continue;
    int tmp=hld_query(parent[u],sp[i][u],rt[i],rt[y]);
    if((1<<i)-tmp<=k)
    {
      u=sp[i][u];
      k-=((1<<i)-tmp);
    }
  }
  if(u==v)
  {
    cout<<-1<<endl;
    return ;
  }
  if(k==0)
  {
    cout<<u<<endl;
    return ;
  }
  if(v==lc)
  {
    cout<<-1<<endl;
    return ;
  }
  u=v;
  cout<<
  int tt=hld_query(parent[u],lc,rt[i],rt[y])-(add[lc]<=y);
  cout<<tt<<endl;
  for(int i=18;i>=0;i--)
  {
    if(sp[i][u]==-1)continue;
    if(level[sp[i][u]]<level[lc])continue;
    int tmp=hld_query(parent[u],sp[i][u],rt[i],rt[y]);
    if(tt-tmp<=k)
    {
      k-=(tt-tmp);
      u=sp[i][u];
    }
  }
  if(k==0)cout<<u<<endl;
  else cout<<-1<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(!x)root=i;
    else
    {
      adj[i].push_back(x);
      adj[x].push_back(i);
    }
  }
  dfs(root,-1,1);
  hld(root,-1,1);
  sparse();
   int q;cin>>q;
  for(int i=1;i<=q;i++)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int x;cin>>x;
      add[x]=i;
      rt[i]=++szz;
      upd(rt[i],1,n,rt[i-1],pos[x]);
    }
    else
    {
      rt[i]=rt[i-1];
      int a,b,k,y;cin>>a>>b>>k>>y;
      int lc=lca(a,b);
      //cout<<"lc "<<lc<<endl;
      solve(a,b,k,y,lc,i);
    }
  }
  return 0;
}