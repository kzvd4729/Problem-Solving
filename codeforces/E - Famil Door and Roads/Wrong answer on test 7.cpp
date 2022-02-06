/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/15/2018 20:41                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 545 ms                                          memory_used: 13400 KB                             
*  problem: https://codeforces.com/contest/629/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,m,u,v,lsz[N+2],low[N+2];
int up[N+2],usz[N+2],parent[N+2];
int sp[N+2][20],level[N+2],total;
vector<int>adj[N+2];
void dfs(int node,int par,int hg)
{
  lsz[node]=1;
  parent[node]=par;
  level[node]=hg;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,hg+1);
    lsz[node]+=lsz[x];
    low[node]+=low[x]+lsz[x];
  }
}
void dds(int node,int par,int sz,int sm)
{
  usz[node]=sz;
  up[node]=sm;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dds(x,node,sz+lsz[node]-lsz[x],sm+low[node]-low[x]-lsz[x]+sz+lsz[node]-lsz[x]);
  }
}
void sparse(void)
{
  memset(sp,-1,sizeof(sp));
  for(int i=1;i<=n;i++)sp[i][0]=parent[i];
  for(int j=1;j<=17;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(sp[i][j-1]==-1)continue;
      sp[i][j]=sp[sp[i][j-1]][j-1];
    }
  }
}
void finaly(int uu,int vv)
{
  if(level[uu]<level[vv])swap(uu,vv);
  int ans=0;
  for(int i=17;i>=0;i--)
  {
    if(sp[uu][i]==-1)continue;
    if(level[sp[uu][i]]>level[vv])
    {
      uu=sp[uu][i];
      ans+=(1<<i);
    }
  }
  cout<<setprecision(10)<<fixed;
  if(parent[uu]==vv)
  {
    ans++;
    ans++;
    //cout<<up[v]<<endl;
    total=ans*lsz[u]*(lsz[v]+usz[v]-lsz[uu])+(low[v]+up[v]-low[uu]-lsz[uu])*lsz[u]+low[u]*(lsz[v]+usz[v]-lsz[uu]);
    double pr=total*1.00/(lsz[u]*1.00*(lsz[v]+usz[v]-lsz[uu]));
    cout<<pr<<endl;
    return ;
  }
  if(level[uu]>level[vv])
  {
    uu=parent[uu];
    ans++;
  }
  for(int i=17;i>=0;i--)
  {
    if(sp[uu][i]==-1||sp[vv][i]==-1)continue;
    if(sp[uu][i]==sp[vv][i])continue;
    uu=sp[uu][i];
    vv=sp[vv][i];
    ans+=2*(1<<i);
  }
  ans+=2;
  ans++;
  ///cout<<ans<<endl;
  total=ans*lsz[u]*lsz[v]+low[v]*lsz[u]+low[u]*lsz[v];
  double pr=total*1.00/(lsz[u]*1.00*lsz[v]);
  cout<<pr<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<n;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1,0);
  dds(1,-1,0,0);
//  for(int i=1;i<=n;i++)
//    cout<<up[i]<<" ";
//  cout<<endl;
  sparse();
  while(m--)
  {
    cin>>u>>v;
    if(level[u]<level[v])swap(u,v);
    finaly(u,v);
  }
  return 0;
}