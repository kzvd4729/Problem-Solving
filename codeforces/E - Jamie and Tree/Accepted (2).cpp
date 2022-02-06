/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/31/2018 20:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1044 ms                                         memory_used: 28500 KB                             
*  problem: https://codeforces.com/contest/916/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int vl[N+2],tim,st[N+2];
int par[N+2],level[N+2];
int sp[N+2][22],n,ed[N+2];
long seg[5*N],lazy[5*N];
vector<int>adj[N+2];
void too_lazy(int node,int lo,int hi)
{
  seg[node]+=(lazy[node]*1LL*(hi-lo+1));
  if(lo!=hi)
  {
    lazy[node*2]+=lazy[node];
    lazy[node*2+1]+=lazy[node];
  }
  lazy[node]=0;
}
void upd(int node,int lo,int hi,int lt,int rt,int up)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]+=up;
    too_lazy(node,lo,hi);return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,up);
  upd(node*2+1,md+1,hi,lt,rt,up);
  seg[node]=seg[node*2]+seg[node*2+1];
}
long query(int node,int lo,int hi,int lt,int rt)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  long p1=query(node*2,lo,md,lt,rt);
  long p2=query(node*2+1,md+1,hi,lt,rt);
  return p1+p2;
}
void dfs(int node,int fro,int h)
{
  ++tim;st[node]=tim;
  upd(1,1,n,st[node],st[node],vl[node]);
  par[node]=fro;level[node]=h;
  for(auto xx:adj[node])
  {
    if(xx==fro)continue;
    dfs(xx,node,h+1);
  }
  ed[node]=tim;
}
void sparse(void)
{
  memset(sp,-1,sizeof(sp));
  for(int i=1;i<=n;i++)
    sp[i][0]=par[i];
  for(int j=1;j<=20;j++)
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
  if(level[u]<level[v])swap(u,v);
  for(int i=20;i>=0;i--)
  {
    if(sp[u][i]==-1)continue;
    if(level[sp[u][i]]>=level[v])
      u=sp[u][i];
  }
  if(u==v)return u;
  for(int i=20;i>=0;i--)
  {
    if(sp[u][i]==-1||sp[v][i]==-1)continue;
    if(sp[u][i]==sp[v][i])continue;
    u=sp[u][i];v=sp[v][i];
  }
  return par[u];
}
bool is_in_path(int u,int v,int w)
{
  if(w==-1)return false;
  if(level[w]<level[lca(u,v)])return false;
  if(lca(u,w)==w||lca(v,w)==w)return true;
  else return false;
}
void update(int u,int v,int rt,int x)
{
  if(is_in_path(u,v,rt))
  {
    upd(1,1,n,st[1],ed[1],x);
    return ;
  }
  int lc=lca(u,v);
  for(int i=20;i>=0;i--)
  {
    if(sp[rt][i]==-1)continue;
    if(level[sp[rt][i]]<level[lc])continue;
    if(!is_in_path(u,v,sp[rt][i]))rt=sp[rt][i];
  }
  if(is_in_path(u,v,par[rt]))
  {
    upd(1,1,n,st[1],ed[1],x);
    upd(1,1,n,st[rt],ed[rt],-x);
  }
  else upd(1,1,n,st[lc],ed[lc],x);
}
void query(int v,int rt)
{
  if(v==rt)
  {
    cout<<query(1,1,n,1,n)<<" ";
    return ;
  }
  for(int i=20;i>=0;i--)
  {
    if(sp[rt][i]==-1)continue;
    if(level[sp[rt][i]]>level[v])
      rt=sp[rt][i];
  }
  if(par[rt]==v)cout<<query(1,1,n,1,n)-query(1,1,n,st[rt],ed[rt])<<" ";
  else cout<<query(1,1,n,st[v],ed[v])<<" ";
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>n>>q;
  for(int i=1;i<=n;i++)
    cin>>vl[i];
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1,1);sparse();
  int rt=1;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int v;cin>>v;
      rt=v;
    }
    else if(ty==2)
    {
      int u,v,x;cin>>u>>v>>x;
      update(u,v,rt,x);
    }
    else
    {
      int v;cin>>v;
      query(v,rt);
    }
  }
  return 0;
}