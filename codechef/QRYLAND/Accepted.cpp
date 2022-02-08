/****************************************************************************************
*  @author: kzvd4729                                         created: 29-06-2019 21:50:36                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.88 sec                                        memory_used: 116M                                 
*  problem: https://www.codechef.com/LTIME73A/problems/QRYLAND
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=250000;
const long mod=1000001011,bs=193;
long qm[N+2],pw[N+2],seg[5*N+2],n,aa[N+2];
/**************** HLD *****************/
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
void upd(long node,long lo,long hi,long id,long vl)
{
  if(lo==hi){seg[node]=vl;return ;}
  long md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=(seg[node*2]+seg[node*2+1])%mod;
}
long get(long node,long lo,long hi,long lt,long rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  long md=(lo+hi)/2;
  return (get(node*2,lo,md,lt,rt)+get(node*2+1,md+1,hi,lt,rt))%mod;
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
long Hqry(long u,long lc)
{
  long ret=0;
  while(Anc[u]!=Anc[lc])
  {
    long v=Anc[u];
    ret=(ret+get(1,1,n,Ent[v],Ent[u]))%mod;
    u=Par[v];
  }
  return (ret+get(1,1,n,Ent[lc],Ent[u]))%mod;
}
pair<long,long>Path(long u,long v)
{
  long d,ret=0;long lc=Lca(u,v,d);
  ret=(Hqry(u,lc)+Hqry(v,lc))%mod;
  ret=(ret-Hqry(lc,lc)+mod)%mod;return {d+1,ret};
}
////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]=1;
  for(long i=1;i<=N;i++)
  {
    pw[i]=(pw[i-1]*bs)%mod;
    qm[i]=(pw[i]+qm[i-1])%mod;
  }
  long t;cin>>t;
  while(t--)
  {
    long q;cin>>n>>q;
    memset(seg,0,sizeof(seg));
    Tim=0;
    for(int i=1;i<=n;i++)
      Adj[i].clear();
    for(long i=1;i<=n;i++)cin>>aa[i];
    for(long i=1;i<n;i++)
    {
      long u,v;cin>>u>>v;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }
    Reckon(1,-1,0);Build_Sparse(n);Anc[1]=1;HLD(1,-1);
    for(long i=1;i<=n;i++)
      upd(1,1,n,Ent[i],pw[aa[i]]);
    while(q--)
    {
      long ty;cin>>ty;
      if(ty==1)
      {
        long u,v;cin>>u>>v;
        pair<long,long>p=Path(u,v);
        if(p.second==qm[p.first])cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
      }
      else
      {
        long x,z;cin>>x>>z;
        upd(1,1,n,Ent[x],pw[z]);
      }
    }
  }
  return 0;
}