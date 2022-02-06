/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/14/2020 13:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 670 ms                                          memory_used: 39400 KB                             
*  problem: https://codeforces.com/contest/449/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5,inf=1e18;
vector<pair<long,long> >adj[N+2];
long d[N+2],cnt;
priority_queue<vector<long> >pq;
void dijkstra(long n)
{
  for(long i=1;i<=n;i++)d[i]=inf;
  d[1]=0;
  for(auto x:adj[1])pq.push({-x.second,1,x.first});
   while(pq.size())
  {
    vector<long>v=pq.top();pq.pop();
    long nd=v[2],c=-v[0];if(d[nd]!=inf)continue;
    d[nd]=c;
    if(v[1]==-1)cnt--;
     for(auto x:adj[nd])
    {
      if(d[x.first]!=inf)continue;
      pq.push({-(c+x.second),1,x.first});
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m,k;cin>>n>>m>>k;
  for(long i=1;i<=m;i++)
  {
    long u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  cnt=k;
  for(long i=1;i<=k;i++)
  {
    long v,w;cin>>v>>w;
    pq.push({-w,-1,v});
  }
  dijkstra(n);cout<<cnt<<endl;
  return 0;
}