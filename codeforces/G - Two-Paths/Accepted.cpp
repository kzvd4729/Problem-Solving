/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2020 16:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1388 ms                                         memory_used: 82400 KB                             
*  problem: https://codeforces.com/contest/1000/problem/G
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=4e5;
int a[N+2];
long sub[N+2],up[N+2];
vector<pair<int,int> >ad[N+2];
void dfs(int nd,int pr)
{
  sub[nd]=a[nd];
  for(auto x:ad[nd])
  {
    if(x.first==pr)continue;dfs(x.first,nd);
    sub[nd]+=max(0LL,sub[x.first]-x.second*2LL);
  }
}
void dds(int nd,int pr,long y)
{
  up[nd]=y;long nw=sub[nd];
  for(auto x:ad[nd])
  {
    if(x.first==pr)continue;
    long con=max(0LL,sub[x.first]-x.second*2LL);
    //cout<<nd<<" "<<x.first<<" "<<con<<endl;
    dds(x.first,nd,max(0LL,y+nw-con-x.second*2LL));
  }
}
long ds[N+2];
void dfs2(int nd,int pr,long d)
{
  ds[nd]=d;
  for(auto x:ad[nd])
  {
    if(x.first==pr)continue;
    dfs2(x.first,nd,d+sub[x.first]-x.second-max(0LL,sub[x.first]-x.second*2LL));
  }
}
int lev[N+2],sp[N+2][20+2];
vector<int>adj[N+2];
void reckon(int n,int p,int h)
{
  sp[n][0]=p;lev[n]=h;
  for(auto x:adj[n])
    if(x!=p)reckon(x,n,h+1);
}
void sparse(int n)
{
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if(sp[i][j-1]!=-1)
        sp[i][j]=sp[sp[i][j-1]][j-1];
    }
  }
}
int lca(int u,int v)
{
  if(lev[u]<lev[v])swap(u,v);
  for(int i=20;i>=0;i--)
  {
    if(lev[u]-(1<<i)>=lev[v])
      u=sp[u][i];
  }
  if(u==v)return u;
  for(int i=20;i>=0;i--)
  {
    if(sp[u][i]==sp[v][i])continue;
    u=sp[u][i],v=sp[v][i];
  }
  return sp[u][0];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=1;i<n;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    ad[u].push_back({v,w});ad[v].push_back({u,w});
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,-1);dds(1,-1,0);
  //for(int i=1;i<=n;i++)cout<<i<<" "<<sub[i]<<endl;
  //cout<<endl<<endl;
  //for(int i=1;i<=n;i++)cout<<i<<" "<<up[i]<<endl;
  reckon(1,-1,0);sparse(n);
  dfs2(1,-1,0);
  while(q--)
  {
    int u,v;cin>>u>>v;
    if(lev[u]<lev[v])swap(u,v);
    int lc=lca(u,v);
    cout<<ds[u]+ds[v]-2*ds[lc]+up[lc]+sub[lc]<<'\n';
  }
  return 0;
}