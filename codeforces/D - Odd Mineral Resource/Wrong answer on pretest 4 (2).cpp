/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/07/2021 22:45                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 46500 KB                             
*  problem: https://codeforces.com/contest/1479/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=3e5,inf=1e9,mod=1e9+7;
  /*
mo's on tree path: complexity n sqrt(n)
solves the query on tree path offline.
*/
const int sq=400;
vector<int>adj[N+2];
int ent[N+2],ext[N+2],tim,flt[N+N+2],sp[N+2][21],lev[N+2],vis[N+2];
struct query
{
  int lt,rt,lc,id;
}qr[N+2];
bool cmp(query a,query b)
{
  if(a.lt/sq!=b.lt/sq)return a.lt<b.lt;return a.rt<b.rt;
}
void dfs(int node,int par,int h)
{
  ent[node]=++tim,sp[node][0]=par,flt[tim]=node,lev[node]=h;
  for(auto x:adj[node])if(x!=par)dfs(x,node,h+1);
  ext[node]=++tim,flt[tim]=node;
}
void sparse(int n)
{
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if(sp[i][j-1]!=-1)sp[i][j]=sp[sp[i][j-1]][j-1];
    }
  }
}
int lca(int u,int v)
{
  if(lev[u]<lev[v])swap(u,v);
  for(int i=20;i>=0;i--)if(lev[u]-(1<<i)>=lev[v])u=sp[u][i];
  if(u==v)return u;
  for(int i=20;i>=0;i--)if(sp[u][i]!=sp[v][i])u=sp[u][i],v=sp[v][i];
  return sp[u][0];
}
//eveything is 1 indexed
int a[N+2],ll[N+2],rr[N+2],fr[N+2],ans[N+2];
bitset<N+2>bt;
void solve(vector<pair<int,int> >vc,int n)
{
  dfs(1,-1,0);sparse(n);int q=0;
  for(auto x:vc)
  {
    ++q;
    int u=x.first,v=x.second,lc=lca(x.first,x.second);
    if(ent[u]>ent[v])swap(u,v);
    if(u==lc)qr[q]={ent[u],ent[v],0,q};//don't need lc;
    else qr[q]={ext[u],ent[v],lc,q};
  }
  sort(qr+1,qr+q+1,cmp);qr[0].lt=1,qr[0].rt=0;
  for(int l=1;l<=q;l++)
  {
    for(int i=qr[l].lt;i<qr[l-1].lt;i++)
    {
      int x=flt[i];vis[x]^=1;
      bt.flip(a[x]);
    }
    for(int i=qr[l-1].rt+1;i<=qr[l].rt;i++)
    {
      int x=flt[i];vis[x]^=1;
      bt.flip(a[x]);
    }
    for(int i=qr[l-1].lt;i<qr[l].lt;i++)
    {
      int x=flt[i];vis[x]^=1;
      bt.flip(a[x]);
    }
    for(int i=qr[l].rt+1;i<=qr[l-1].rt;i++)
    {
      int x=flt[i];vis[x]^=1;
      bt.flip(a[x]);
    }
     //store current answer to ans[qr[l].id];
    int id=qr[l].id;
    if(bt[rr[id]])ans[id]=rr[id];
    else
    {
      bt[rr[id]]=1;
      int g=bt._Find_next(ll[id]-1);
       if(g<rr[id])ans[id]=g;
      bt[rr[id]]=0;
    }
    if(ans[id]!=-1)continue;
     if(qr[l].lc)
    {
      //add value of lc with ans[qr[l].id];
      int x=flt[qr[l].lc];
      if(a[x]>=ll[id]&&a[x]<=rr[id])
        ans[id]=a[x];
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  vector<pair<int,int> >vc;
  for(int i=1;i<=q;i++)
  {
    int u,v;cin>>u>>v>>ll[i]>>rr[i];
    vc.push_back({u,v});
  }
  memset(ans,-1,sizeof ans);
  solve(vc,n);
   for(int i=1;i<=q;i++)cout<<ans[i]<<" ";cout<<endl;
   return 0;
}