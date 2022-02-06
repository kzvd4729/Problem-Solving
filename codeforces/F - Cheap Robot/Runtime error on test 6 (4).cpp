/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/28/2020 15:40                        
*  solution_verdict: Runtime error on test 6                 language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 127100 KB                            
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
const long N=3e5;
const long inf=1e18;
long n,qd[N+2];
vector<pair<long,long> >adj[N+2];
long d[N+2],id[N+2],td[N+2],tid[N+2];
void go(vector<long>v)
{
  for(long i=1;i<=n;i++)d[i]=inf,qd[i]=0;queue<long>q;
  for(auto x:v)q.push(x),d[x]=0,id[x]=x,qd[x]=1;
   while(q.size())
  {
    long u=q.front();q.pop();qd[u]=0;
    for(auto x:adj[u])
    {
      if(d[u]+x.second>=d[x.first])continue;
      d[x.first]=d[u]+x.second;id[x.first]=id[u];
      if(qd[x.first]==0)q.push(x.first),qd[x.first]=1;
    }
  }
}
long par[N+2];
long get(long x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
long lev[N+2],sp[N+2][22];long mx[N+2][22];
void reckon(long n,long p,long h,long d)
{
  sp[n][0]=p,lev[n]=h,mx[n][0]=d;
  for(auto x:adj[n])
    if(x.first!=p)reckon(x.first,n,h+1,x.second);
}
void sparse(long n)
{
  for(long j=1;j<=20;j++)
  {
    for(long i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];//mx[i][j]=mx[i][j-1];
      if(sp[i][j-1]!=-1)
      {
        sp[i][j]=sp[sp[i][j-1]][j-1];
        mx[i][j]=max(mx[i][j-1],mx[sp[i][j-1]][j-1]);
      }
    }
  }
}
long lca(long u,long v)
{
  if(lev[u]<lev[v])swap(u,v);
  long ret=0;
  for(long i=20;i>=0;i--)
  {
    if(lev[u]-(1<<i)>=lev[v])
    {
      ret=max(ret,mx[u][i]);u=sp[u][i];
    }
  }
  if(u==v)return ret;
  for(long i=20;i>=0;i--)
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
  long m,k,q;cin>>n>>m>>k>>q;
  for(long i=1;i<=m;i++)
  {
    long u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});adj[v].push_back({u,w});
  }
  vector<vector<long> >ed,tr;
  for(long p=0;p<20;p++)
  {
    vector<long>a,b;
    for(long j=1;j<=k;j++)
    {
      if(j&(1<<p))a.push_back(j);
      else b.push_back(j);
    }
    if(a.size()==0||b.size()==0)continue;
    go(a);for(long i=1;i<=n;i++)td[i]=d[i],tid[i]=id[i];
    go(b);for(long i=1;i<=n;i++)ed.push_back({d[i]+td[i],id[i],tid[i]});
  }
  sort(ed.begin(),ed.end());
  for(long i=1;i<=k;i++)par[i]=i;
  for(auto x:ed)
  {
    long a=get(x[1]),b=get(x[2]);
    if(a==b)continue;
    par[a]=b;tr.push_back(x);
  }
  if(tr.size()<k-1)assert(0);
  for(long i=1;i<=n;i++)adj[i].clear();
  for(auto x:tr)
  {
    adj[x[1]].push_back({x[2],x[0]});
    adj[x[2]].push_back({x[1],x[0]});
  }
  reckon(1,-1,0,0);sparse(k);
  while(q--)
  {
    long u,v;cin>>u>>v;cout<<lca(u,v)<<"\n";
  }
  return 0;
}