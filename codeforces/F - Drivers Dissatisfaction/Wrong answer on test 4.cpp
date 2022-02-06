/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/28/2019 20:54                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 39300 KB                             
*  problem: https://codeforces.com/contest/733/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
struct edge
{
  int u,v,ds,lm,id;
}ed[N+2];
vector<pair<int,int> >ab[N+2];
pair<int,int>seg[5*N+2];
void upd(int node,int lo,int hi,int id,int ds,int eid)
{
  if(lo>id||hi<id)return ;
  if(lo==hi)
  {
    seg[node]={ds,eid};return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,id,ds,eid);
  upd(node*2+1,md+1,hi,id,ds,eid);
  if(seg[node*2].first>=seg[node*2+1].first)
    seg[node]=seg[node*2];
  else seg[node]=seg[node*2+1];
}
pair<int,int>qry(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt||lt>rt)return {-1,0};
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  pair<int,int>p1=qry(node*2,lo,md,lt,rt);
  pair<int,int>p2=qry(node*2+1,md+1,hi,lt,rt);
  if(p1.first>=p2.first)return p1;return p2;
}
int Par[N+2],Lev[N+2],Sp[N+2][22];
vector<int>Adj[N+2];int Sub[N+2];
int Ent[N+2],Ext[N+2],Tim,Anc[N+2];
void Reckon(int n,int p,int h)
{
  Par[n]=p;Lev[n]=h;Sub[n]=1;
  for(int i=0;i<Adj[n].size();i++)
  {
    int x=Adj[n][i];if(x==p)continue;
    Reckon(x,n,h+1);Sub[n]+=Sub[x];
    if(Sub[x]>=Sub[Adj[n][0]])
    {
      swap(Adj[n][i],Adj[n][0]);
      swap(ab[n][i],ab[n][0]);
    }
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
void HLD(int n,int p,int ds,int id)
{
  Ent[n]=++Tim;upd(1,1,N,Tim,ds,id);
  for(int i=0;i<Adj[n].size();i++)
  {
    int x=Adj[n][i];if(x==p)continue;//Anc[r]=r;
    if(x==Adj[n][0])Anc[x]=Anc[n];
    else Anc[x]=x;HLD(x,n,ab[n][i].first,ab[n][i].second);
  }
  Ext[n]=Tim;
}
pair<int,int>Hqry(int u,int lc)
{
  pair<int,int>ret={-1,0};
  while(Anc[u]!=Anc[lc])
  {
    int v=Anc[u];
    ret=max(ret,qry(1,1,N,Ent[v],Ent[u]));
    u=Par[v];
  }
  return max(ret,qry(1,1,N,Ent[lc]+1,Ent[u]));
}
int par[N+2];
bool cmp(edge a,edge b)
{
  return a.ds<b.ds;
}
int _find(int x)
{
  if(par[x]==x)return x;
  return par[x]=_find(par[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)cin>>ed[i].ds;
  for(int i=1;i<=m;i++)cin>>ed[i].lm;
  for(int i=1;i<=m;i++)
  {
    cin>>ed[i].u>>ed[i].v;ed[i].id=i;
  }
  int s;cin>>s;
  sort(ed+1,ed+m+1,cmp);
  for(int i=1;i<=n;i++)
    par[i]=i;
  long mst=0,mn=1e18;vector<int>med;int f=0,xyz;
  for(int i=1;i<=m;i++)
  {
    int r1=_find(ed[i].u),r2=_find(ed[i].v);
    if(r1==r2)continue;
    Adj[ed[i].u].push_back(ed[i].v);
    Adj[ed[i].v].push_back(ed[i].u);
    if(f==0)xyz=i,f=1;
    par[r1]=r2;
    //cout<<ed[i].u<<" ---- "<<ed[i].v<<endl;
    ab[ed[i].u].push_back({ed[i].ds,ed[i].id});
    ab[ed[i].v].push_back({ed[i].ds,ed[i].id});
    mst+=ed[i].ds;med.push_back(i);
    mn=min(mn,ed[i].lm*1LL);
  }
  long ans=mst-s/mn,rem=-1,add=-1;
  Anc[1]=1;Reckon(1,-1,0);Build_Sparse(n);HLD(1,-1,-1,0);
  for(int i=1;i<=m;i++)
  {
    int lc,d;lc=Lca(ed[i].u,ed[i].v,d);
    pair<int,int>ret=max(Hqry(ed[i].u,lc),Hqry(ed[i].v,lc));
    //cout<<ed[i].u<<" "<<ed[i].v<<" "<<ret.first<<" "<<ret.second<<endl;
    long tmp=mst;//if(ret.first<=0)assert(0);///
    tmp-=ret.first;tmp+=ed[i].ds;
    tmp-=s/ed[i].lm;
    if(tmp<ans)
    {
      ans=tmp;rem=ret.second;add=i;
    }
  }
  cout<<ans<<endl;
  if(add==-1)
  {
    for(auto x:med)
    {
      if(x==xyz)cout<<ed[x].id<<" "<<ed[x].ds-s/ed[x].lm<<endl;
      else cout<<ed[x].id<<" "<<ed[x].ds<<endl;
    }
  }
  else
  {
    med.push_back(add);
    for(auto x:med)
    {
      if(x==add)cout<<ed[x].id<<" "<<ed[x].ds-s/ed[x].lm<<endl;
      else if(ed[x].id==rem)continue;
      else cout<<ed[x].id<<" "<<ed[x].ds<<endl;
    }
  }
  return 0;
}