/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/12/2018 23:55                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4900 KB                              
*  problem: https://codeforces.com/contest/1076/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int vis[N+2];
vector<pair<int,int> >adj[N+2];
map<pair<int,int>,int>mp;
int main() 
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
    if(u>v)swap(u,v);mp[{u,v}]=i;
  }
  priority_queue<pair<long,pair<int,int> > >pq;
  for(auto x:adj[1])pq.push({-x.second,{1,x.first}});
  set<int>ans;vis[1]=1;
  while(pq.size())
  {
    pair<long,pair<int,int> >p=pq.top();pq.pop();
    int u=p.second.first,v=p.second.second;
    if(u>v)swap(u,v);long cs=-p.first;
    if(ans.size()<k)ans.insert(mp[{u,v}]);
    vis[p.second.second]=1;
    for(auto x:adj[p.second.second])
    {
      if(vis[x.first])continue;
      pq.push({-(cs+x.second),{p.second.second,x.first}});
    }
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}