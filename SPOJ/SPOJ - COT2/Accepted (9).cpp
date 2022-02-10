/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-24 00:07:03                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 3650                                       memory_used (MB): 34.8                            
*  problem: https://vjudge.net/problem/SPOJ-COT2
****************************************************************************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define long long long
using namespace std;
using namespace __gnu_pbds;
const int N=1e5,sq=350;
int aa[N+2],ent[N+2],ext[N+2],tim,ans[N+2];
int sp[N+2][22],lev[N+2],vis[N+2],nd[N+2];
vector<int>adj[N+2];
gp_hash_table<int,int>fr;
struct query
{
  int lt,rt,id,lc;
}qr[N+N+2];
bool cmp(query A,query B)
{
  if(A.lt/sq!=B.lt/sq)
    return A.lt<B.lt;
  return A.rt<B.rt;
}
void sparse(int n)
{
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(sp[i][j-1]==-1)continue;
      sp[i][j]=sp[sp[i][j-1]][j-1];
    }
  }
}
int lca(int u,int v)
{
  if(lev[u]<lev[v])swap(u,v);;
  for(int i=20;i>=0;i--)
  {
    if(lev[u]-(1<<i)>=lev[v])
      u=sp[u][i];
  }
  if(u==v)return u;
  for(int i=20;i>=0;i--)
  {
    if(sp[u][i]==-1||sp[v][i]==-1)continue;
    if(sp[u][i]==sp[v][i])continue;
    u=sp[u][i];v=sp[v][i];
  }
  return sp[u][0];
}
void dfs(int node,int par,int hg)
{
  ent[node]=++tim;sp[node][0]=par;
  nd[tim]=node;lev[node]=hg;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,hg+1);
  }
  ext[node]=++tim;nd[tim]=node;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(sp,-1,sizeof(sp));dfs(1,-1,0);
  sparse(n);
  for(int i=1;i<=m;i++)
  {
    int u,v,lc;cin>>u>>v;
    if(ent[u]>ent[v])swap(u,v);
    lc=lca(u,v);
    if(lc==u)qr[i]={ent[u],ent[v],i,0};
    else qr[i]={ext[u],ent[v],i,lc};
  }
  sort(qr+1,qr+m+1,cmp);
  int cnt=0;
  for(int i=qr[1].lt;i<=qr[1].rt;i++)
  {
    int x=nd[i];vis[x]^=1;
    if(vis[x])
    {
      fr[aa[x]]++;
      if(fr[aa[x]]==1)cnt++;
    }
    else
    {
      fr[aa[x]]--;
      if(fr[aa[x]]==0)cnt--;
    }
  }
  ans[qr[1].id]=cnt;
  if(qr[1].lc)
  {
    int x=qr[1].lc;
    if(!fr[aa[x]])ans[qr[1].id]++;
  }
  for(int q=2;q<=m;q++)
  {
    for(int i=qr[q].lt;i<qr[q-1].lt;i++)
    {
      int x=nd[i];vis[x]^=1;
      if(vis[x])
      {
        fr[aa[x]]++;
        if(fr[aa[x]]==1)cnt++;
      }
      else
      {
        fr[aa[x]]--;
        if(fr[aa[x]]==0)cnt--;
      }
    }
    for(int i=qr[q-1].rt+1;i<=qr[q].rt;i++)
    {
      int x=nd[i];vis[x]^=1;
      if(vis[x])
      {
        fr[aa[x]]++;
        if(fr[aa[x]]==1)cnt++;
      }
      else
      {
        fr[aa[x]]--;
        if(fr[aa[x]]==0)cnt--;
      }
    }
    for(int i=qr[q-1].lt;i<qr[q].lt;i++)
    {
      int x=nd[i];vis[x]^=1;
      if(vis[x])
      {
        fr[aa[x]]++;
        if(fr[aa[x]]==1)cnt++;
      }
      else
      {
        fr[aa[x]]--;
        if(fr[aa[x]]==0)cnt--;
      }
    }
    for(int i=qr[q].rt+1;i<=qr[q-1].rt;i++)
    {
      int x=nd[i];vis[x]^=1;
      if(vis[x])
      {
        fr[aa[x]]++;
        if(fr[aa[x]]==1)cnt++;
      }
      else
      {
        fr[aa[x]]--;
        if(fr[aa[x]]==0)cnt--;
      }
    }
    ans[qr[q].id]=cnt;
    if(qr[q].lc)
    {
      int x=qr[q].lc;
      if(!fr[aa[x]])ans[qr[q].id]++;
    }
  }
  for(int i=1;i<=m;i++)
    cout<<ans[i]<<"\n";
  return 0;
}