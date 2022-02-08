/****************************************************************************************
*  @author: kzvd4729                                         created: 03-03-2019 23:50:38                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 1.26 sec                                        memory_used: 598.5M                               
*  problem: https://www.codechef.com/problems/ABX03
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long nw,rt[N+2];vector<long>cst[N+2];
struct segment
{
  long l,r,a[7];
}seg[N*80+2];
void upd(long node,long lo,long hi,long pnode,long id,long msk,long c)
{
  if(lo==hi)
  {
    for(long i=0;i<7;i++)
      seg[node].a[i]=seg[pnode].a[i]+bool(msk&(1<<i))*c;
    return ;
  }
  long md=(lo+hi)/2;
  if(id<=md)
  {
    seg[node].l=++nw;seg[node].r=seg[pnode].r;
    upd(seg[node].l,lo,md,seg[pnode].l,id,msk,c);
  }
  else
  {
    seg[node].r=++nw;seg[node].l=seg[pnode].l;
    upd(seg[node].r,md+1,hi,seg[pnode].r,id,msk,c);
  }
  for(long i=0;i<7;i++)
    seg[node].a[i]=seg[seg[node].l].a[i]+seg[seg[node].r].a[i];
}
long qry(long node,long lo,long hi,long pnode,long lt,long rt,long i)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node].a[i]-seg[pnode].a[i];
  long md=(lo+hi)/2;
  long p1=qry(seg[node].l,lo,md,seg[pnode].l,lt,rt,i);
  long p2=qry(seg[node].r,md+1,hi,seg[pnode].r,lt,rt,i);
  return p1+p2;
}
long make_mask(long c)
{
  long msk=0;
  if(c%2==0&&c%3&&c%5)msk|=(1<<0);
  if(c%3==0&&c%2&&c%5)msk|=(1<<1);
  if(c%5==0&&c%2&&c%3)msk|=(1<<2);
  if(c%2==0&&c%3==0&&c%5)msk|=(1<<3);
  if(c%3==0&&c%5==0&&c%2)msk|=(1<<4);
  if(c%2==0&&c%5==0&&c%3)msk|=(1<<5);
  if(c%2==0&&c%3==0&&c%5==0)msk|=(1<<6);
  //cout<<c<<"  ---------- "<<msk<<endl;
  return msk;
}
long Par[N+2],Lev[N+2],Sp[N+2][22];
vector<long>Adj[N+2];long Sub[N+2];
long Ent[N+2],Ext[N+2],Tim,Anc[N+2];
void Reckon(long n,long p,long h)
{
  Par[n]=p;Lev[n]=h;Sub[n]=1;
  for(long i=0;i<Adj[n].size();i++)
  {
    long x=Adj[n][i];
    if(x==p)continue;Reckon(x,n,h+1);
    Sub[n]+=Sub[x];
    if(Sub[x]>=Sub[Adj[n][0]])
    {
      swap(Adj[n][i],Adj[n][0]);
      swap(cst[n][i],cst[n][0]);
    }
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
void HLD(long n,long p,long c)
{
  Ent[n]=++Tim;rt[Tim]=++nw;
  long msk=make_mask(c);
  //cout<<n<<"        "<<c<<endl;
  upd(rt[Tim],1,N,rt[Tim-1],c,msk,c);
  for(long i=0;i<Adj[n].size();i++)
  {
    long x=Adj[n][i];
    if(x==p)continue;//Anc[r]=r;
    if(x==Adj[n][0])Anc[x]=Anc[n];
    else Anc[x]=x;HLD(x,n,cst[n][i]);
  }
  Ext[n]=Tim;
}
long _a(long a,long b,long c)
{
  return max(max(a,b),c);
}
long _b(long a,long b,long c)
{
  return min(min(a,b),c);
}
long Hqry(long u,long lc,long a,long b,long c,long d,long e,long f)
{
  long ret=0;
  while(Anc[u]!=Anc[lc])
  {
    long v=Anc[u];
    if(a<=b)ret+=qry(rt[Ent[u]],1,N,rt[Ent[v]-1],a,b,0);
    if(c<=d)ret+=qry(rt[Ent[u]],1,N,rt[Ent[v]-1],c,d,1);
    if(e<=f)ret+=qry(rt[Ent[u]],1,N,rt[Ent[v]-1],e,f,2);
    if(max(a,c)<=min(b,d))ret+=qry(rt[Ent[u]],1,N,rt[Ent[v]-1],max(a,c),min(b,d
        ),3);
    if(max(c,e)<=min(d,f))ret+=qry(rt[Ent[u]],1,N,rt[Ent[v]-1],max(c,e),min(d,f
        ),4);
    if(max(a,e)<=min(b,f))ret+=qry(rt[Ent[u]],1,N,rt[Ent[v]-1],max(a,e),min(b,f
        ),5);
    if(_a(a,c,e)<=_b(b,d,f))ret+=qry(rt[Ent[u]],1,N,rt[Ent[v]-1],_a(a,c,e),_b(b
        ,d,f),6);
    u=Par[v];
  }
  long v=lc;
  if(a<=b)ret+=qry(rt[Ent[u]],1,N,rt[Ent[v]-1],a,b,0);
  if(c<=d)ret+=qry(rt[Ent[u]],1,N,rt[Ent[v]-1],c,d,1);
  if(e<=f)ret+=qry(rt[Ent[u]],1,N,rt[Ent[v]-1],e,f,2);
  if(max(a,c)<=min(b,d))ret+=qry(rt[Ent[u]],1,N,rt[Ent[v]-1],max(a,c),min(b,d),3
      );
  if(max(c,e)<=min(d,f))ret+=qry(rt[Ent[u]],1,N,rt[Ent[v]-1],max(c,e),min(d,f),4
      );
  if(max(a,e)<=min(b,f))ret+=qry(rt[Ent[u]],1,N,rt[Ent[v]-1],max(a,e),min(b,f),5
      );
  if(_a(a,c,e)<=_b(b,d,f))ret+=qry(rt[Ent[u]],1,N,rt[Ent[v]-1],_a(a,c,e),_b(b,d
      ,f),6);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,q;cin>>n>>q;
  for(long i=1;i<n;i++)
  {
    long u,v,c;cin>>u>>v>>c;
    Adj[u].push_back(v);Adj[v].push_back(u);
    cst[u].push_back(c);cst[v].push_back(c);
  }
  Anc[1]=1;Reckon(1,-1,0);Build_Sparse(n);HLD(1,-1,1);
  long last=0;
  while(q--)
  {
    last%=100000;
    long u,v,a,b,c,d,e,f;cin>>u>>v>>a>>b>>c>>d>>e>>f;
    u+=last,v+=last,a+=last,b+=last,c+=last,d+=last;
    e+=last,f+=last;
    long lc,yz;lc=Lca(u,v,yz);
    //cout<<u<<" "<<v<<endl;
    last=Hqry(u,lc,a,b,c,d,e,f)+Hqry(v,lc,a,b,c,d,e,f);
    last-=2*Hqry(lc,lc,a,b,c,d,e,f);
    cout<<last<<"\n";
  }
  return 0;
}