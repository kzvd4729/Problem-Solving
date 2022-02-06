/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/28/2020 14:55                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 34000 KB                             
*  problem: https://codeforces.com/contest/1253/problem/F
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=1e5;
int n,qd[N+2];
vector<pair<int,long> >adj[N+2];
long d[N+2],id[N+2],td[N+2],tid[N+2];
void go(vector<int>v)
{
  for(int i=1;i<=n;i++)d[i]=1e18;queue<int>q;
  for(auto x:v)q.push(x),d[x]=0,id[x]=x,qd[x]=1;
   while(q.size())
  {
    int u=q.front();q.pop();qd[u]=0;
    for(auto x:adj[u])
    {
      if(d[u]+x.second>=d[x.first])continue;
      d[x.first]=d[u]+x.second;id[x.first]=id[u];
      if(qd[x.first]==0)q.push(x.first),qd[x.first]=1;
    }
  }
}
int par[N+2];
int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
int lev[N+2],sp[N+2][21];long mx[N+2][21];
void reckon(int n,int p,int h,long d)
{
  sp[n][0]=p,lev[n]=h,mx[n][0]=d;
  for(auto x:adj[n])
    if(x.first!=p)reckon(x.first,n,h+1,x.second);
}
void sparse(int n)
{
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];mx[i][j]=mx[i][j-1];
      if(sp[i][j-1]!=-1)
      {
        sp[i][j]=sp[sp[i][j-1]][j-1];
        mx[i][j]=max(mx[i][j],mx[sp[i][j-1]][j-1]);
      }
    }
  }
}
long lca(int u,int v)
{
  if(lev[u]<lev[v])swap(u,v);
  long ret=0;
  for(int i=20;i>=0;i--)
  {
    if(lev[u]-(1<<i)>=lev[v])
    {
      ret=max(ret,mx[u][i]);u=sp[u][i];
    }
  }
  if(u==v)return ret;
  for(int i=20;i>=0;i--)
  {
    if(sp[u][i]==sp[v][i])continue;
    ret=max(ret,mx[u][i]);ret=max(ret,mx[v][i]);
    u=sp[u][i],v=sp[v][i];
  }
  ret=max(ret,mx[u][0]);ret=max(ret,mx[v][0]);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m,k,q;cin>>n>>m>>k>>q;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});adj[v].push_back({u,w});
  }
  vector<vector<long> >ed,tr;
  for(int i=0; ;i++)
  {
    vector<int>a,b;
    for(int j=1;j<=k;j++)
    {
      if(j&(1<<i))a.push_back(j);
      else b.push_back(j);
    }
    if(a.size()==0||b.size()==0)break;
    go(a);for(int i=1;i<=n;i++)td[i]=d[i],tid[i]=id[i];
    go(b);for(int i=1;i<=n;i++)ed.push_back({d[i]+td[i],id[i],tid[i]});
  }
  sort(ed.begin(),ed.end());
  for(int i=1;i<=n;i++)par[i]=i;
  for(auto x:ed)
  {
    int a=get(x[1]),b=get(x[2]);
    if(a==b)continue;
    par[a]=b;tr.push_back(x);
  }
  for(int i=1;i<=n;i++)adj[i].clear();
  for(auto x:tr)
  {
    adj[x[1]].push_back({x[2],x[0]});
    adj[x[2]].push_back({x[1],x[0]});
  }
  reckon(1,-1,0,0);sparse(k);
  while(q--)
  {
    int u,v;cin>>u>>v;cout<<lca(u,v)<<"\n";
  }
  return 0;
}