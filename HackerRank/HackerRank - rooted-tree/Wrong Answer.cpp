/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-28 14:34:48                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-rooted-tree
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
const long mod=1e9+7;
long aa[N+2];
struct segment
{
  long smd,smv,smk,lzv,lzk;
}seg[5*N+2];
void too_lazy(long node,long lo,long hi)
{
  seg[node].smv=(seg[node].smv+(hi-lo+1)*seg[node].lzv)%mod;
  seg[node].smk=(seg[node].smk+seg[node].lzk)%mod;
  if(lo!=hi)
  {
    seg[node*2].lzv=(seg[node*2].lzv+seg[node].lzv)%mod;
    seg[node*2+1].lzv=(seg[node*2+1].lzv+seg[node].lzv)%mod;
    seg[node*2].lzk=(seg[node*2].lzk+seg[node].lzk)%mod;
    seg[node*2+1].lzk=(seg[node*2+1].lzk+seg[node].lzk)%mod;
  }
  seg[node].lzv=0;seg[node].lzk=0;
}
void build(long node,long lo,long hi)
{
  if(lo==hi)
  {
    seg[node].smd=aa[lo];return ;
  }
  long md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  seg[node].smd=(seg[node*2].smd+seg[node*2+1].smd)%mod;
}
void upd(long node,long lo,long hi,long lt,long rt,long v,long k)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    seg[node].lzv+=v;seg[node].lzk+=k;
    seg[node].lzv=(seg[node].lzv+mod)%mod;
    seg[node].lzk=(seg[node].lzk+mod)%mod;
    too_lazy(node,lo,hi);return ;
  }
  long md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,v,k);
  upd(node*2+1,md+1,hi,lt,rt,v,k);
  seg[node].smv=(seg[node*2].smv+seg[node*2+1].smv)%mod;
  seg[node].smk=(seg[node*2].smk+seg[node*2+1].smk)%mod;
}
long qry(long node,long lo,long hi,long lt,long rt)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return (seg[node].smv+seg[node].smd*seg[node].smk)%mod;
  long md=(lo+hi)/2;
  long p1=qry(node*2,lo,md,lt,rt);
  long p2=qry(node*2+1,md+1,hi,lt,rt);
  return (p1+p2)%mod;
}
long Par[N+2],Lev[N+2],Sp[N+2][22];
vector<long>Adj[N+2];long Sub[N+2];
long Ent[N+2],Ext[N+2],Tim,Anc[N+2];
void Reckon(long n,long p,long h)
{
  Par[n]=p;Lev[n]=h;Sub[n]=1;
  for(auto &x:Adj[n])
  {
    if(x==p)continue;Reckon(x,n,h+1);
    Sub[n]+=Sub[x];
    if(Sub[x]>=Sub[Adj[n][0]])
      swap(x,Adj[n][0]);
  }
}
void Build_Sparse(long n)
{
  memset(Sp,-1,sizeof(Sp));
  for(long i=1;i<=n;i++)
    Sp[i][0]=Par[i];
  for(long j=1;j<=20;j++)
  {
    for(long i=1;i<=n;i++)
    {
      if(Sp[i][j-1]==-1)continue;
      Sp[i][j]=Sp[Sp[i][j-1]][j-1];
    }
  }
}
long Lca(long u,long v,long &d)
{
  if(Lev[u]<Lev[v])swap(u,v);d=0;
  for(long i=20;i>=0;i--)
  {
    if(Lev[u]-(1<<i)>=Lev[v])
      u=Sp[u][i],d+=(1<<i);
  }
  if(u==v)return u;
  for(long i=20;i>=0;i--)
  {
    if(Sp[u][i]==-1||Sp[v][i]==-1)continue;
    if(Sp[u][i]==Sp[v][i])continue;
    u=Sp[u][i];v=Sp[v][i];d+=2*(1<<i);
  }
  d+=2;return Par[u];
}
void HLD(long n,long p)
{
  Ent[n]=++Tim;
  for(auto x:Adj[n])
  {
    if(x==p)continue;//Anc[r]=r;
    if(x==Adj[n][0])Anc[x]=Anc[n];
    else Anc[x]=x;HLD(x,n);
  }
  Ext[n]=Tim;
}
long Hqry(long u,long lc,long n)
{
  long ret=0;
  while(Anc[u]!=Anc[lc])
  {
    long v=Anc[u];
    ret=(ret+qry(1,1,n,Ent[v],Ent[u]))%mod;
    u=Par[v];
  }
  return (ret+qry(1,1,n,Ent[lc],Ent[u]))%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,e,r;cin>>n>>e>>r;
  for(long i=1;i<n;i++)
  {
    long u,v;cin>>u>>v;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }
  Anc[r]=r;Reckon(r,-1,0);Build_Sparse(n);HLD(r,-1);

  for(long i=1;i<=n;i++)
    aa[Ent[i]]=Lev[i];
  build(1,1,n);
  while(e--)
  {
    char c;cin>>c;
    if(c=='U')
    {
      long t,v,k;cin>>t>>v>>k;
      upd(1,1,n,Ent[t],Ext[t],v,k);
      long ds=Lev[t];
      upd(1,1,n,Ent[t],Ext[t],(-(ds*k)%mod+mod)%mod,0);
    }
    else
    {
      long a,b,lc,d;cin>>a>>b;
      lc=Lca(a,b,d);
      long sm=Hqry(a,lc,n);
      sm=(sm+Hqry(b,lc,n))%mod;
      sm=(sm-Hqry(lc,lc,n)+mod)%mod;
      cout<<(sm+mod)%mod<<"\n";
    }
  }
  return 0;
}