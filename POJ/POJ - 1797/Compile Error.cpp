/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-05 23:37:32                      
*  solution_verdict: Compile Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-1797
****************************************************************************************/
#include<iostream>
#include<vector>
#include<queue>
#define long long long
using namespace std;
int mn,n,m,u,v,w,t,tc,vis[1003];
vector<pair<int,int> >adj[1003];
priority_queue<pair<int,int> >pq;
int dijkstra()
{
  while(pq.size())pq.pop();
  pq.push({1e9,1});
  mn=1e9;
  while(pq.size())
  {
    pair<int,int>p=pq.top();
    pq.pop();
    int node=p.second;
    mn=min(mn,p.first);
    if(node==n)return mn;
    vis[node]=1;
    for(int i=0;i<adj[node].size();i++)
    {
      pair<int,int>x=adj[node][i];
      if(vis[x.first])continue;
      pq.push({x.second,x.first});
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    while(m--)
    {
      cin>>u>>v>>w;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
    cout<<"Scenario #"<<++tc<<":"<<endl;
    cout<<dijkstra()<<endl;
    cout<<endl;
  }
  return 0;
}