/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-27 23:51:16                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-subtrees-and-paths
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int seg[5*N+2],lazy[5*N+2];
void too_lazy(int node,int lo,int hi)
{
  seg[node]+=lazy[node];
  if(lo!=hi)
  {
    lazy[node*2]+=lazy[node];
    lazy[node*2+1]+=lazy[node];
  }
  lazy[node]=0;
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]+=vl;too_lazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);
  upd(node*2+1,md+1,hi,lt,rt,vl);
  seg[node]=max(seg[node*2],seg[node*2+1]);
}
int qry(int node,int lo,int hi,int lt,int rt)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  int p1=qry(node*2,lo,md,lt,rt);
  int p2=qry(node*2+1,md+1,hi,lt,rt);
  return max(p1,p2);
}
int Par[N+2],Lev[N+2],Sp[N+2][22];
vector<int>Adj[N+2];int Sub[N+2];
int Ent[N+2],Ext[N+2],Tim,Anc[N+2];
void Reckon(int n,int p,int h)
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
void Build_Sparse(int n)
{
  memset(Sp,-1,sizeof(Sp));
  for(int i=1;i<=n;i++)
    Sp[i][0]=Par[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(Sp[i][j-1]==-1)continue;
      Sp[i][j]=Sp[Sp[i][j-1]][j-1];
    }
  }
}
int Lca(int u,int v,int &d)
{
  if(Lev[u]<Lev[v])swap(u,v);d=0;
  for(int i=20;i>=0;i--)
  {
    if(Lev[u]-(1<<i)>=Lev[v])
      u=Sp[u][i],d+=(1<<i);
  }
  if(u==v)return u;
  for(int i=20;i>=0;i--)
  {
    if(Sp[u][i]==-1||Sp[v][i]==-1)continue;
    if(Sp[u][i]==Sp[v][i])continue;
    u=Sp[u][i];v=Sp[v][i];d+=2*(1<<i);
  }
  d+=2;return Par[u];
}
void HLD(int n,int p)
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
int Hqry(int u,int lc,int n)
{
  int ret=0;
  while(Anc[u]!=Anc[lc])
  {
    int v=Anc[u];
    ret=max(ret,qry(1,1,n,Ent[v],Ent[u]));
    u=Par[v];
  }
  return max(ret,qry(1,1,n,Ent[lc],Ent[u]));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }
  Anc[1]=1;Reckon(1,-1,0);Build_Sparse(n);HLD(1,-1);
  int q;cin>>q;
  while(q--)
  {
    string s;cin>>s;
    if(s=="add")
    {
      int x,vl;cin>>x>>vl;
      upd(1,1,n,Ent[x],Ext[x],vl);
    }
    else
    {
      int u,v;cin>>u>>v;int d;
      int lc=Lca(u,v,d);
      cout<<max(Hqry(u,lc,n),Hqry(v,lc,n))<<"\n";
    }
  }
  return 0;
}