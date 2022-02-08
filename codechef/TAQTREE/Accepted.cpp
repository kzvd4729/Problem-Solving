/****************************************************************************************
*  @author: kzvd4729                                         created: 15-11-2018 22:23:27                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.09 sec                                        memory_used: 39.6M                                
*  problem: https://www.codechef.com/problems/TAQTREE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,sz[N+2],anc[N+2],parent[N+2],level[N+2];
int bit[N+2],cost[N+2],ent[N+2],tim,sp[N+2][22];
vector<pair<int,int> >adj[N+2];
pair<int,int>pp[N+2];
void upd(int x,int vl)
{
  for( ;x<=n;x+=x&-x)
    bit[x]+=vl;
}
int qry(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)
    ret+=bit[x];
  return ret;
}
void dfs(int node,int par,int lv)
{
  sz[node]=1;parent[node]=par;level[node]=lv;
  for(auto &x:adj[node])
  {
    if(x.first==par)continue;
    dfs(x.first,node,lv+1);sz[node]+=sz[x.first];
    if(sz[x.first]>=sz[adj[node][0].first])
      swap(x,adj[node][0]);
  }
}
void hld(int node,int par,int cs)
{
  cost[node]=cs;ent[node]=++tim;
  upd(ent[node],cost[node]);
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    if(x==adj[node][0])anc[x.first]=anc[node];
    else anc[x.first]=x.first;
      hld(x.first,node,x.second);
  }
}
void build_sparse(void)
{
  memset(sp,-1,sizeof(sp));
  for(int i=1;i<=n;i++)
    sp[i][0]=parent[i];
  for(int j=1;j<=20;j++)
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
  if(level[u]<level[v])swap(u,v);
  for(int i=20;i>=0;i--)
  {
    if(sp[u][i]==-1)continue;
    if(level[sp[u][i]]>=level[v])
      u=sp[u][i];
  }
  if(u==v)return u;
  for(int i=20;i>=0;i--)
  {
    if(sp[u][i]==-1||sp[v][i]==-1)continue;
    if(sp[u][i]==sp[v][i])continue;
    u=sp[u][i];v=sp[v][i];
  }
  return parent[u];
}
int hld_query(int u,int v)
{
  int ret=0;
  while(anc[u]!=anc[v])
  {
    ret+=qry(ent[u])-qry(ent[anc[u]]-1);
    u=parent[anc[u]];
  }
  return ret+qry(ent[u])-qry(ent[v]);
}
int query(int u,int v)
{
  int lc=lca(u,v);
  return hld_query(u,lc)+hld_query(v,lc);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    if(u>v)swap(u,v);pp[i]={u,v};
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  dfs(1,-1,0);hld(1,-1,0);build_sparse();
  int q;cin>>q;
  while(q--)
  {
    int ty,u,v;cin>>ty>>u>>v;
    if(ty==1)
    {
      int nd;
      if(ent[pp[u].second]>ent[pp[u].first])
        nd=pp[u].second;
      else nd=pp[u].first;
      upd(ent[nd],-cost[nd]);
      cost[nd]=v;upd(ent[nd],cost[nd]);
    }
    else cout<<query(u,v)<<"\n";
  }
  return 0;
}