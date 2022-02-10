/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-23 16:08:43                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 2830                                       memory_used (MB): 222.2                           
*  problem: https://vjudge.net/problem/SPOJ-COT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long lev[N+2],sz,parent[N+2];
long sp[22][N+2],n,rt[N+2];
long arr[N+2],mx,mn,ans,con;
vector<long>adj[N+2];
struct persistent
{
  long l,r,sm;
}seg[80*N+2];
void upd(long node,long lo,long hi,long pnode,long id)
{
  if(lo==hi)
  {
    seg[node].sm=seg[pnode].sm+1;
    return ;
  }
  long md=(lo+hi)/2;
  if(id<=md)
  {
    seg[node].l=++sz;
    upd(seg[node].l,lo,md,seg[pnode].l,id);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    seg[node].r=++sz;
    upd(seg[node].r,md+1,hi,seg[pnode].r,id);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
void qry(long ndu,long ndv,long ndl,long lo,long hi,long kth)
{
  if(lo==hi)
  {
    ans=lo;return ;
  }
  long md=(lo+hi)/2;long ch;
  if(ndu==ndv)
  {
    ch=seg[seg[ndu].l].sm-seg[seg[ndl].l].sm;
    if(con>=lo&&con<=md)ch++;
  }
  else
  {
    ch=seg[seg[ndu].l].sm+seg[seg[ndv].l].sm-2*seg[seg[ndl].l].sm;
    if(con>=lo&&con<=md)ch++;
  }
  if(ch>=kth)qry(seg[ndu].l,seg[ndv].l,seg[ndl].l,lo,md,kth);
  else qry(seg[ndu].r,seg[ndv].r,seg[ndl].r,md+1,hi,kth-ch);
}
void dfs(long node,long par,long lv)
{
  lev[node]=lv;parent[node]=par;
  long tmp=par;if(tmp==-1)tmp=0;
  rt[node]=++sz;upd(rt[node],mn,mx,rt[tmp],arr[node]);
  for(long i=0;i<adj[node].size();i++)
  {
    long x=adj[node][i];
    if(x==par)continue;
    dfs(x,node,lv+1);
  }
}
void build(void)
{
  memset(sp,-1,sizeof(sp));
  for(long i=1;i<=n;i++)sp[0][i]=parent[i];
  for(long j=1;j<=16;j++)
  {
    for(long i=1;i<=n;i++)
    {
      if(sp[j-1][i]==-1)continue;
      sp[j][i]=sp[j-1][sp[j-1][i]];
    }
  }
}
long lca(long u,long v)
{
  if(lev[u]<lev[v])swap(u,v);
  for(long i=16;i>=0;i--)
  {
    if(sp[i][u]==-1)continue;
    if(lev[sp[i][u]]>=lev[v])u=sp[i][u];
  }
  if(u==v)return u;
  for(long i=16;i>=0;i--)
  {
    if(sp[i][u]==-1||sp[i][v]==-1)continue;
    if(sp[i][u]==sp[i][v])continue;
    u=sp[i][u];v=sp[i][v];
  }
  return parent[u];
}
int main()
{
  long q;scanf("%lld%lld",&n,&q);mx=-1e18,mn=1e18;
  for(long i=1;i<=n;i++)
  {
    scanf("%lld",&arr[i]);mx=max(mx,arr[i]);mn=min(mn,arr[i]);
  }
  for(long i=1;i<n;i++)
  {
    long u,v;scanf("%lld%lld",&u,&v);
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,-1,0);build();
  while(q--)
  {
    long u,v,kth;scanf("%lld%lld%lld",&u,&v,&kth);
    long lc=lca(u,v);con=arr[lc];
    qry(rt[u],rt[v],rt[lc],mn,mx,kth);
    printf("%lld\n",ans);
  }
  return 0;
}