/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-11 20:09:07                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 120                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10986
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
const int N=2e4;
int t,tc,sr,tr,n,m,u,v,w,dis[N+2];
vector<pair<int,int> >adj[N+2];
int dijkstra(int sr,int tr)
{
  priority_queue<pair<int,int> >pq;
  for(int i=0;i<=n;i++)dis[i]=inf;
  pq.push({0,sr});
  dis[sr]=0;
  while(pq.size())
  {
    pair<int,int>p=pq.top();
    pq.pop();
    for(auto x:adj[p.second])
    {
      if(dis[p.second]+x.second<dis[x.first])
      {
        dis[x.first]=dis[p.second]+x.second;
        pq.push({-dis[x.first],x.first});
      }
    }
  }
  return dis[tr];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>m>>sr>>tr;
    for(int i=0;i<=n;i++)
      adj[i].clear();
    while(m--)
    {
      cin>>u>>v>>w;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
    int tmp=dijkstra(sr,tr);
    cout<<"Case #"<<++tc<<": ";
    if(tmp==inf)cout<<"unreachable"<<endl;
    else cout<<tmp<<endl;
  }
  return 0;
}