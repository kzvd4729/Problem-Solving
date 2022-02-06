/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2018 15:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 9800 KB                              
*  problem: https://codeforces.com/contest/20/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long inf=1e14;
int n,m,u,v,w;
vector<pair<int,int> >adj[N+2];
int link[N+2];
long dijkstra(void)
{
  long dis[N+2];
  for(int i=1;i<=n;i++)dis[i]=inf;
  priority_queue<pair<long,long> >pq;
  pq.push({0,1});
  dis[1]=0;
  while(pq.size())
  {
    pair<long,long>p=pq.top();
    pq.pop();
    for(auto x:adj[p.second])
    {
      if(x.second+dis[p.second]<dis[x.first])
      {
        dis[x.first]=dis[p.second]+x.second;
        pq.push({-dis[x.first],x.first});
        link[x.first]=p.second;
      }
    }
  }
  return dis[n];
}
void print(void)
{
  vector<int>ans;
  ans.push_back(n);
  while(n!=1)
  {
    n=link[n];
    ans.push_back(n);
  }
  reverse(ans.begin(),ans.end());
  for(auto x:ans)cout<<x<<" ";
  cout<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  if(dijkstra()==inf)cout<<-1<<endl,exit(0);
  print();
  return 0;
}