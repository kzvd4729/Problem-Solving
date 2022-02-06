/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/06/2018 19:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 310 ms                                          memory_used: 8300 KB                              
*  problem: https://codeforces.com/contest/95/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e3,inf=1e14;
long dis[N+2][N+2],n,fn[N+2],tx[N+2],cs[N+2];
vector<pair<long,long> >adj[N+2];
void dijkstra(long nd)
{
  for(long i=1;i<=n;i++)dis[nd][i]=inf;
  priority_queue<pair<long,long> >pq;
  pq.push({0,nd});dis[nd][nd]=0;
  while(pq.size())
  {
    pair<long,long>p=pq.top();pq.pop();
    for(auto x:adj[p.second])
    {
      if(-p.first+x.second<dis[nd][x.first])
      {
        dis[nd][x.first]=-p.first+x.second;
        pq.push({-dis[nd][x.first],x.first});
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long m;cin>>n>>m;long x,y;cin>>x>>y;
  while(m--)
  {
    long u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  for(long i=1;i<=n;i++)
    dijkstra(i);
  for(long i=1;i<=n;i++)
    cin>>tx[i]>>cs[i];
   for(long i=1;i<=n;i++)fn[i]=inf;
  priority_queue<pair<long,long> >pq;
  pq.push({0,x});fn[x]=0;
  while(pq.size())
  {
    pair<long,long>p=pq.top();pq.pop();
    for(long i=1;i<=n;i++)
    {
      if(p.second==i)continue;
      if(dis[p.second][i]>tx[p.second])continue;
      if(-p.first+cs[p.second]<fn[i])
      {
        fn[i]=-p.first+cs[p.second];
        pq.push({-fn[i],i});
      }
    }
  }
  if(fn[y]>=inf)fn[y]=-1;
  cout<<fn[y]<<endl;
  return 0;
}