/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/11/2019 22:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 389 ms                                          memory_used: 25700 KB                             
*  problem: https://codeforces.com/gym/102215/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5,inf=1e9;
 //..............................................................................
long bit[2][N+2];
void upd(int x,long ml,long sm)
{
  for( ;x<=N;x+=(x&-x))
    bit[0][x]+=ml,bit[1][x]+=sm;
}
long get(int x)
{
  long ml=0,sm=0,bg=x;
  for( ;x>0;x-=(x&-x))
    ml+=bit[0][x],sm+=bit[1][x];
  return ml*bg+sm;
}
void range(int lo,int hi,long vl)
{
  upd(lo,vl,-vl*(lo-1));
  upd(hi,-vl,vl*hi);
}
long get(int lt,int rt)
{
  return get(rt)-get(lt-1);
}
//..............................................................................
 vector<int>adj[N+2];
int sub[N+2],ent[N+2],tim,anc[N+2],par[N+2],lev[N+2];
void dfs(int n,int p,int l)
{
  sub[n]=1,par[n]=p,lev[n]=l;
  for(auto x:adj[n])
  {
    if(x==p)continue;
    dfs(x,n,l+1);sub[n]+=sub[x];
  }
}
void hld(int n,int p)
{
  ent[n]=++tim;
  int mx=-1,b=-1;
  for(auto x:adj[n])
  {
    if(x==p)continue;
    if(sub[x]>mx)mx=sub[x],b=x;
  }
  if(b!=-1)
  {
    anc[b]=anc[n];hld(b,n);
  }
  for(auto x:adj[n])
  {
    if(x==p||x==b)continue;
    anc[x]=x;hld(x,n);
  }
}
int hQry(int u,int v,int vl)
{
  while(true)
  {
    //cout<<u<<" "<<v<<endl;
    if(lev[u]<lev[v])swap(u,v);
    if(anc[u]==anc[v])
    {
      range(ent[v],ent[u],vl);
      return v;
    }
    if(lev[anc[u]]<lev[anc[v]])swap(u,v);
    range(ent[anc[u]],ent[u],vl);
    u=par[anc[u]];
  }
}
int f;
int hQry(int u,int v)
{
  while(true)
  {
    if(lev[u]<lev[v])swap(u,v);
    if(anc[u]==anc[v])
    {
      f|=get(ent[v],ent[u]);
      return v;
    }
    if(lev[anc[u]]<lev[anc[v]])swap(u,v);
    f|=get(ent[anc[u]],ent[u]);
    u=par[anc[u]];
  }
}
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,-1,0);anc[1]=1;hld(1,-1);
  // for(int i=1;i<=n;i++)cout<<anc[i]<<" ";
  //   cout<<endl;
  int q;cin>>q;
  //cout<<"here"<<endl;
  while(q--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
      cin>>aa[i];
    n++;aa[n]=aa[n-1];
     int lc=aa[1];
    for(int i=2;i<=n;i++)
      lc=hQry(lc,aa[i],1);
     for(int i=1;i<=m;i++)cin>>bb[i];
    m++;bb[m]=bb[m-1];
     f=0;
    lc=bb[1];
    for(int i=2;i<=m;i++)
      lc=hQry(lc,bb[i]);
    if(!f)cout<<"YES\n";
    else cout<<"NO\n";
     lc=aa[1];
    for(int i=2;i<=n;i++)
      lc=hQry(lc,aa[i],-1);
  }
  return 0;
}