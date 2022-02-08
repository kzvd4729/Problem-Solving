/****************************************************************************************
*  @author: kzvd4729                                         created: 03-03-2019 23:49:18                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.39 sec                                        memory_used: 51.4M                                
*  problem: https://www.codechef.com/problems/TRAVTREE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int bit[2][N+2];
void upd(int i,int x,int vl)
{
  for( ;x<=N;x+=x&-x)
    bit[i][x]+=vl;
}
int qry(int i,int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)
    ret+=bit[i][x];
  return ret;
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
int Hqry(int u,int lc)
{
  int ret=0;
  while(Anc[u]!=Anc[lc])
  {
    int v=Anc[u];
    ret+=qry(0,Ent[u])-qry(0,Ent[v]-1);
    u=Par[v];
  }
  return ret+qry(0,Ent[u])-qry(0,Ent[lc]-1);
}
void Hupd(int u,int lc)
{
  while(Anc[u]!=Anc[lc])
  {
    int v=Anc[u];
    upd(1,Ent[v],1);upd(1,Ent[u]+1,-1);
    u=Par[v];
  }
  if(u==lc)return ;
  upd(1,Ent[lc]+1,1);upd(1,Ent[u]+1,-1);
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
    int u,v;cin>>u>>v;
    int d,lc,ans;lc=Lca(u,v,d);
    ans=Hqry(u,lc)+Hqry(v,lc)-Hqry(lc,lc);
    ans+=qry(1,Ent[lc]);
    upd(0,Ent[lc],1);Hupd(u,lc);
    Hupd(v,lc);//Hupd(u,lc);
    cout<<ans<<"\n";
  }
  return 0;
}