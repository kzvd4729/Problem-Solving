/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/08/2019 13:34                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 26000 KB                             
*  problem: https://codeforces.com/contest/1051/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long inf=1e18;
int par[N+2],cst[N+2],lvl[N+2];
int sp[N+2][20];long ds[N+2][20],mt[50][50];
vector<pair<int,int> >adj[N+2];
int _find(int x)
{
  if(x==par[x])return x;
  return par[x]=_find(par[x]);
}
void dfs(int node,int pr,int cs,int lv)
{
  par[node]=pr;lvl[node]=lv;cst[node]=cs;
  for(auto x:adj[node])
  {
    if(x.first==pr)continue;
    dfs(x.first,node,x.second,lv+1);
  }
}
void sparse(int n)
{
  memset(sp,-1,sizeof(sp));
  for(int i=1;i<=n;i++)
    sp[i][0]=par[i],ds[i][0]=cst[i];
  for(int j=1;j<20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(sp[i][j-1]==-1)continue;
      sp[i][j]=sp[sp[i][j-1]][j-1];
      ds[i][j]=ds[i][j-1]+ds[sp[i][j-1]][j-1];
    }
  }
}
long dist(int u,int v)
{
  if(lvl[u]<lvl[v])swap(u,v);
  long ret=0;
  for(int i=19;i>=0;i--)
  {
    if(sp[u][i]==-1)continue;
    if(lvl[sp[u][i]]>=lvl[v])
      ret+=ds[u][i],u=sp[u][i];
  }
  if(u==v)return ret;
  for(int i=19;i>=0;i--)
  {
    if(sp[u][i]==sp[v][i])continue;
    ret+=ds[u][i]+ds[v][i];
    u=sp[u][i],v=sp[v][i];
  }
  return ret+ds[u][0]+ds[v][0];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  vector<pair<int,pair<int,int>>>ed,un;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    ed.push_back({w,{u,v}});
  }
  for(int i=1;i<=n;i++)par[i]=i;
  for(auto x:ed)
  {
    int r1=_find(x.second.first);
    int r2=_find(x.second.second);
    if(r1==r2){un.push_back(x);continue;}
    par[r1]=r2;
    adj[x.second.first].push_back({x.second.second,x.first});
    adj[x.second.second].push_back({x.second.first,x.first});
  }
  dfs(1,-1,0,0);sparse(n);int q;cin>>q;
  while(q--)
  {
    vector<int>nodes;
    for(auto x:un)
    {
      nodes.push_back(x.second.first);
      nodes.push_back(x.second.second);
    }
    int u,v;cin>>u>>v;
    nodes.push_back(u);nodes.push_back(v);
    sort(nodes.begin(),nodes.end());
    nodes.erase(unique(nodes.begin(),nodes.end()),nodes.end());
    int x=nodes.size();
    for(int i=0;i<x;i++)
      for(int j=0;j<x;j++)
        mt[i][j]=inf;
    for(int i=0;i<x;i++)
      mt[i][i]=0;
    for(auto x:un)
    {
      int id1=lower_bound(nodes.begin(),nodes.end(),x.second.first)-nodes.begin();
      int id2=lower_bound(nodes.begin(),nodes.end(),x.second.second)-nodes.begin();
      mt[id1][id2]=min(mt[id1][id2],x.first*1LL);
      mt[id2][id1]=min(mt[id2][id1],x.first*1LL);
    }
    for(int i=0;i<x;i++)
    {
      for(int j=i+1;j<x;j++)
      {
        long now=dist(nodes[i],nodes[j]);
        mt[i][j]=min(mt[i][j],now);
        mt[j][i]=min(mt[j][i],now);
      }
    }
    int a,b;
    for(int i=0;i<x;i++)
    {
      if(nodes[i]==u)a=i;
      if(nodes[i]==v)b=i;
    }
    for(int k=0;k<x;k++)
      for(int j=0;j<x;j++)
        mt[a][j]=min(mt[a][j],mt[a][k]+mt[k][j]);
    cout<<mt[a][b]<<"\n";
  }
  return 0;
}