/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2019 00:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1653 ms                                         memory_used: 97400 KB                             
*  problem: https://codeforces.com/contest/696/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5,inf=1e16;
long lazy[5*N+2];
struct segment
{
  long ex,mx,id;
}seg[5*N+2];
void too_lazy(long node,long lo,long hi)
{
  seg[node].ex+=lazy[node];
  if(lo!=hi)
  {
    lazy[node*2]+=lazy[node];
    lazy[node*2+1]+=lazy[node];
  }
  lazy[node]=0;
}
void supd(long node,long lo,long hi,long id,long vl)
{
  too_lazy(node,lo,hi);
  if(lo>id||hi<id)return ;
  if(lo==hi)
  {
    seg[node].mx=vl;seg[node].id=id;
    return ;
  }
  long md=(lo+hi)/2;
  supd(node*2,lo,md,id,vl);
  supd(node*2+1,md+1,hi,id,vl);
  segment p1=seg[node*2],p2=seg[node*2+1];
  if(p1.ex+p1.mx<p2.ex+p2.mx)seg[node]=p1;
  else if(p2.ex+p2.mx<p1.ex+p1.mx)seg[node]=p2;
  else if(p1.id<p2.id)seg[node]=p1;
  else seg[node]=p2;
}
void upd(long node,long lo,long hi,long lt,long rt,long vl)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]+=vl;too_lazy(node,lo,hi);
    return ;
  }
  long md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);
  upd(node*2+1,md+1,hi,lt,rt,vl);
   segment p1=seg[node*2],p2=seg[node*2+1],p;
  if(p1.ex+p1.mx<p2.ex+p2.mx)seg[node]=p1;
  else if(p2.ex+p2.mx<p1.ex+p1.mx)seg[node]=p2;
  else if(p1.id<p2.id)seg[node]=p1;
  else seg[node]=p2;
}
segment qry(long node,long lo,long hi,long lt,long rt)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return {0,inf,0};
  if(lo>=lt&&hi<=rt)return seg[node];
  long md=(lo+hi)/2;
  segment p1=qry(node*2,lo,md,lt,rt);
  segment p2=qry(node*2+1,md+1,hi,lt,rt);
   if(p1.ex+p1.mx<p2.ex+p2.mx)return p1;
  else if(p2.ex+p2.mx<p1.ex+p1.mx)return p2;
  else if(p1.id<p2.id)return p1;
  else return p2;
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
segment _min(segment a,segment b)
{
  if(a.ex+a.mx<b.ex+b.mx)return a;
  if(b.ex+b.mx<a.ex+a.mx)return b;
  if(a.id<b.id)return a;return b;
}
segment Hqry(long u,long lc,long n)
{
  segment ret={inf,inf,0};
  while(Anc[u]!=Anc[lc])
  {
    long v=Anc[u];
    segment p1=qry(1,1,n,Ent[v],Ent[u]);
    ret=_min(ret,p1);u=Par[v];
  }
  segment p1=qry(1,1,n,Ent[lc],Ent[u]);
  return _min(ret,p1);
}
vector<long>ab[N+2];long pt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m,q;cin>>n>>m>>q;
  for(long i=1;i<n;i++)
  {
    long u,v;cin>>u>>v;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }
  Anc[1]=1;Reckon(1,-1,0);Build_Sparse(n);HLD(1,-1);
  for(long i=1;i<=m;i++)
  {
    long x;cin>>x;ab[Ent[x]].push_back(i);
  }
  for(long i=1;i<=n;i++)
  {
    if(ab[i].size()>0)supd(1,1,n,i,ab[i][0]);
    else supd(1,1,n,i,inf);
  }
  while(q--)
  {
    long ty;cin>>ty;
    if(ty==1)
    {
      long u,v,k,d;cin>>u>>v>>k;
      long lc=Lca(u,v,d);vector<long>prt;
      while(k--)
      {
        segment ans=_min(Hqry(u,lc,n),Hqry(v,lc,n));
        //cout<<u<<" "<<v<<" "<<lc<<endl;
        if(ans.mx<=m)
        {
          prt.push_back(ans.mx);pt[ans.id]++;
          if(pt[ans.id]<ab[ans.id].size())
            supd(1,1,n,ans.id,ab[ans.id][pt[ans.id]]);
          else supd(1,1,n,ans.id,inf);
        }
        else break;
      }
      //cout<<"---------------- ";
      cout<<prt.size();
      for(auto x:prt)cout<<" "<<x;
      cout<<"\n";
    }
    else
    {
      long nd,vl;cin>>nd>>vl;
      upd(1,1,n,Ent[nd],Ext[nd],vl);
    }
  }
  return 0;
}