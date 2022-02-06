/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/20/2019 20:32                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 364000 KB                            
*  problem: https://codeforces.com/contest/1253/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
const long inf=1e18;
long dis[N+2],k;
vector<pair<long,long> >adj[N+2];
vector<vector<long> >ed;
void dijkstra(long nd)
{
 dis[nd]=0;priority_queue<pair<long,long> >pq;
 pq.push({0,nd});
 while(pq.size())
 {
  pair<long,long>p=pq.top();pq.pop();
  for(auto x:adj[p.second])
  {
   if(-p.first+x.second<dis[x.first])
   {
    dis[x.first]=-p.first+x.second;pq.push({-dis[x.first],x.first});
    if(x.first<=k)ed.push_back({dis[x.first],nd,x.first});
   }
  }
 }
}
long par[N+2];
long get(long x)
{
 if(x==par[x])return x;
 return par[x]=get(par[x]);
}
 long lev[N+2],sp[N+2][21];long mx[N+2][21];
void reckon(long n,long p,long h,long cs)
{
  sp[n][0]=p,lev[n]=h,mx[n][0]=cs;//cout<<"***"<<cs<<endl;
  for(auto x:adj[n])
    if(x.first!=p)reckon(x.first,n,h+1,x.second);
}
void sparse(long n)
{
  for(long j=1;j<=20;j++)
  {
    for(long i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];mx[i][j]=mx[i][j-1];
      if(sp[i][j-1]!=-1)
        sp[i][j]=sp[sp[i][j-1]][j-1],mx[i][j]=max(mx[i][j],mx[sp[i][j-1]][j-1]);
    }
  }
}
long lca(long u,long v)
{
  if(lev[u]<lev[v])swap(u,v);long m=0;
  for(long i=20;i>=0;i--)
  {
    if(lev[u]-(1<<i)>=lev[v])
    {
      m=max(m,mx[u][i]);u=sp[u][i];
    }
  }
  //cout<<u<<" --> "<<v<<endl;
  if(u==v)return m;
  for(long i=20;i>=0;i--)
  {
    if(sp[u][i]==sp[v][i])continue;
    //cout<<"**"<<i<<endl;
    m=max(m,mx[u][i]);m=max(m,mx[v][i]);
    u=sp[u][i],v=sp[v][i];
  }
  m=max(m,mx[u][0]);m=max(m,mx[v][0]);
  return m;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m,q;cin>>n>>m>>k>>q;
   for(long i=1;i<=m;i++)
  {
   long u,v,w;cin>>u>>v>>w;
   adj[u].push_back({v,w});
   adj[v].push_back({u,w});
  }
  for(long i=1;i<=n;i++)dis[i]=inf;
  for(long i=1;i<=k;i++)dijkstra(i);
   sort(ed.begin(),ed.end());
 for(long i=1;i<=k;i++)par[i]=i;
 for(long i=1;i<=n;i++)adj[i].clear();
 for(auto x:ed)
 {
  long r1=get(x[1]),r2=get(x[2]);
  if(r1!=r2)
  {
   //cout<<x[0]<<" * "<<x[1]<<" * "<<x[2]<<endl;
   par[r1]=r2;adj[x[1]].push_back({x[2],x[0]});
   adj[x[2]].push_back({x[1],x[0]});
  }
 }
 reckon(1,-1,0,0);sparse(k);
 while(q--)
 {
  long u,v;cin>>u>>v;
  cout<<lca(u,v)<<"\n";
 }
  return 0;
}