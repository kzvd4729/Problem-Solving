/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-02 00:23:59                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-QTREE2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
int t,n,level[N+2];
int parent[N+2],cost[N+2];
int sp[18][N+2],ps[18][N+2];
vector<pair<int,int> >adj[N+2];
void dfs(int node,int par,int h,int cs)
{
  cost[node]=cs;
  level[node]=h;
  parent[node]=par;
  for(auto xx:adj[node])
  {
    if(xx.first==par)continue;
    dfs(xx.first,node,h+1,xx.second);
  }
}
void sparse(void)
{
  memset(sp,-1,sizeof(sp));
  for(int i=1;i<=n;i++)
    sp[0][i]=parent[i];
  for(int j=1;j<=16;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(sp[j-1][i]==-1)continue;
      sp[j][i]=sp[j-1][sp[j-1][i]];
    }
  }
  memset(ps,0,sizeof(ps));
  for(int i=1;i<=n;i++)
    ps[0][i]=cost[i];
  for(int j=1;j<=16;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(sp[j-1][i]==-1)continue;
      ps[j][i]=ps[j-1][i]+ps[j-1][sp[j-1][i]];
    }
  }
}
int lca(int u,int v)
{
  if(level[u]<level[v])swap(u,v);
  for(int i=16;i>=0;i--)
  {
    if(sp[i][u]==-1)continue;
    if(level[sp[i][u]]>=level[v])
      u=sp[i][u];
  }
  if(u==v)return u;
  for(int i=16;i>=0;i--)
  {
    if(sp[i][u]==-1||sp[i][v]==-1)continue;
    if(sp[i][u]==sp[i][v])continue;
    u=sp[i][u];
    v=sp[i][v];
  }
  return parent[u];
}
void dist(int u,int v,int lc)
{
  int sum=0;
  for(int i=16;i>=0;i--)
  {
    if(sp[i][u]==-1)continue;
    if(level[sp[i][u]]>=level[lc])
    {
      sum+=ps[i][u];
      u=sp[i][u];
    }
  }
  for(int i=16;i>=0;i--)
  {
    if(sp[i][v]==-1)continue;
    if(level[sp[i][v]]>=level[lc])
    {
      sum+=ps[i][v];
      v=sp[i][v];
    }
  }
  cout<<sum<<endl;
}
void kth(int u,int v,int lc,int k)
{
  k--;
  for(int i=16;i>=0;i--)
  {
    if((1<<i)>k)continue;
    if(sp[i][u]==-1)continue;
    if(level[sp[i][u]]>level[lc])
    {
      u=sp[i][u];
      k-=(1<<i);
    }
  }
  if(!k)
  {
    cout<<u<<endl;
    return ;
  }
  int path=0;u=v;
  for(int i=16;i>=0;i--)
  {
    if(sp[i][u]==-1)continue;
    if(level[sp[i][u]]>=level[lc])
    {
      u=sp[i][u];
      path+=(1<<i);
    }
  }
  path++;u=v;
  k=path-k;
  for(int i=16;i>=0;i--)
  {
    if(sp[i][u]==-1)continue;
    if(level[sp[i][u]]>=level[lc])
    {
      if((1<<i)<=k)
      {
        k-=(1<<i);
        u=sp[i][u];
      }
    }
  }
  cout<<u<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);

  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)
      adj[i].clear();
    for(int i=2;i<=n;i++)
    {
      int u,v,w;cin>>u>>v>>w;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
    dfs(1,-1,1,0);
    sparse();
    string s;
    while(cin>>s)
    {
      if(s=="DONE")break;
      int u,v;cin>>u>>v;
      int lc=lca(u,v);
      if(s=="KTH")
      {
        int k;cin>>k;
        kth(u,v,lc,k);
      }
      else dist(u,v,lc);
    }
    cout<<endl;
  }
  return 0;
}