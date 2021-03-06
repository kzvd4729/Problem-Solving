/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2019 16:43                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 732 ms                                          memory_used: 24300 KB                             
*  problem: https://codeforces.com/contest/536/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int ff[N+2],sz[N+2],anc[N+2],ent[N+2],tim;
int lvl[N+2],sp[N+2][20],ans[N+2];
vector<pair<int,int> >adj[N+2];
struct data
{
  int vl,nd;
}nod[N+2];
bool data_cmp(data a,data b)
{
  return a.vl>b.vl;
}
struct query
{
  int u,v,l,id;
}qq[N+2];
bool cmp(query a,query b)
{
  return a.l>b.l;
}
struct segment
{
  int sm,l,r,f;
}seg[5*N+2];
segment _merge(segment a,segment b)
{
  segment c;
  if(a.f&&b.f)
    c={ff[a.r+b.l],a.r+b.l,a.r+b.l,1};
  else if(a.f)
  {
    c.sm=b.sm-ff[b.l]+ff[a.r+b.l];
    c.l=a.r+b.l;c.r=b.r;c.f=0;
  }
  else if(b.f)
  {
    c.sm=a.sm-ff[a.r]+ff[a.r+b.l];
    c.l=a.l;c.r=b.l+a.r;c.f=0;
  }
  else
  {
    c.sm=a.sm+b.sm-ff[a.r]-ff[b.l]+ff[a.r+b.l];
    c.l=a.l;c.r=b.r;c.f=0;
  }
  return c;
}
void upd(int node,int lo,int hi,int id)
{
  if(lo==hi)
  {
    seg[node]={ff[1],1,1,1};return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id);
  else upd(node*2+1,md+1,hi,id);
  seg[node]=_merge(seg[node*2],seg[node*2+1]);
}
segment qry(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {0,0,0,1};
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  segment p1=qry(node*2,lo,md,lt,rt);
  segment p2=qry(node*2+1,md+1,hi,lt,rt);
  return _merge(p1,p2);
}
void reckon(int node,int par)
{
  sz[node]=1;
  for(auto &x:adj[node])
  {
    if(x.first==par)continue;
    reckon(x.first,node);sz[node]+=sz[x.first];
    if(sz[x.first]>=sz[adj[node][0].first])
      swap(x,adj[node][0]);
  }
}
void hld(int node,int par,int h,int vl)
{
  ent[node]=++tim;lvl[node]=h;
  sp[node][0]=par;nod[node]={vl,node};
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    if(x==adj[node][0])anc[x.first]=anc[node];
    else anc[x.first]=x.first;
    hld(x.first,node,h+1,x.second);
  }
}
void sparse(int n)
{
  for(int j=1;j<20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(sp[i][j-1]!=-1)
        sp[i][j]=sp[sp[i][j-1]][j-1];
    }
  }
}
int lca(int u,int v)
{
  if(lvl[u]<lvl[v])swap(u,v);
  for(int i=19;i>=0;i--)
  {
    if(sp[u][i]==-1)continue;
    if(lvl[sp[u][i]]>=lvl[v])
      u=sp[u][i];
  }
  if(u==v)return u;
  for(int i=19;i>=0;i--)
  {
    if(sp[u][i]==-1||sp[v][i]==-1)continue;
    if(sp[u][i]==sp[v][i])continue;
    u=sp[u][i];v=sp[v][i];
  }
  return sp[u][0];
}
int raise(int u,int a)
{
  for(int i=19;i>=0;i--)
  {
    if((1<<i)<=a)
      u=sp[u][i],a-=(1<<i);
  }
  return u;
}
segment hld_qry1(int u,int lc,int n)
{
  segment s1={0,0,0,1},s2={0,0,0,1};
  while(anc[u]!=anc[lc])
  {
    int v=anc[u];
    s2=qry(1,1,n,ent[v],ent[u]);
    swap(s2.l,s2.r);u=sp[v][0];
    s1=_merge(s1,s2);
  }
  s2=qry(1,1,n,ent[lc],ent[u]);
  //cout<<ent[lc]<<" "<<ent[u]<<endl;
  //cout<<s2.sm<<" "<<s2.l<<" "<<s2.r<<" "<<s2.f<<endl;
  swap(s2.l,s2.r);
  segment s=_merge(s1,s2);
  return _merge(s1,s2);
}
segment hld_qry2(int u,int lc,int n)
{
  segment s1={0,0,0,1},s2={0,0,0,1};
  while(anc[u]!=anc[lc])
  {
    int v=anc[u];
    s2=qry(1,1,n,ent[v],ent[u]);
    u=sp[v][0];s1=_merge(s2,s1);
   }
  s2=qry(1,1,n,ent[lc],ent[u]);swap(s2.l,s2.r);
  return _merge(s2,s1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<n;i++)cin>>ff[i];
  for(int i=1;i<n;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  memset(sp,-1,sizeof(sp));
  reckon(1,-1);anc[1]=1;hld(1,-1,0,2e9);
  sparse(n);sort(nod+1,nod+n+1,data_cmp);
  for(int i=1;i<=q;i++)
  {
    cin>>qq[i].u>>qq[i].v>>qq[i].l;
    qq[i].id=i;
  }
  sort(qq+1,qq+q+1,cmp);
   //upd(1,1,n,5);
  //segment s=qry(1,1,n,4,5);
  //cout<<s.sm<<" --- "<<s.l<<" "<<s.r<<" "<<s.f<<endl;
  /////////////////////////////
  /*cout<<endl;
  for(int i=1;i<=n;i++)
    cout<<nod[i].vl<<" "<<nod[i].nd<<endl;
  cout<<endl;
  for(int i=1;i<=q;i++)
    cout<<qq[i].u<<" "<<qq[i].v<<" "<<qq[i].l<<" "<<qq[i].id<<endl;
  cout<<endl;*/
  //////////////////////////////
   int pt=2;
  for(int i=1;i<=q;i++)
  {
    while(true)
    {
      if(pt>n)break;
      if(nod[pt].vl>=qq[i].l)
      {
        upd(1,1,n,ent[nod[pt].nd]);
        pt++;
      }
      else break;
    }
    int lc=lca(qq[i].u,qq[i].v);
    int u=qq[i].u,v=qq[i].v;
    int d1=lvl[u]-lvl[lc];
    segment s1,s2;
    if(d1>=1)
    {
      int uu=raise(u,d1-1);
      s1=hld_qry1(u,uu,n);
    }
    else s1={0,0,0,1};
    //cout<<"s1*= "<<s1.sm<<endl;
    int d2=lvl[v]-lvl[lc];
    if(d2>=1)
    {
      int vv=raise(v,d2-1);
      s2=hld_qry2(v,vv,n);
    }
    else s2={0,0,0,1};
    //cout<<"s2*= "<<s2.sm<<endl;
    s1=_merge(s1,s2);
     ans[qq[i].id]=s1.sm;
  }
  for(int i=1;i<=q;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}