/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/15/2018 22:41                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1200 KB                              
*  problem: https://codeforces.com/contest/61/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
vector<pair<int,int> >adj[N+2];
long dfs(int node,int par)
{
  vector<long>v;v.push_back(0);
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    v.push_back(x.second*1LL+dfs(x.first,node));
  }
  sort(v.begin(),v.end());
  for(int i=1;i<v.size();i++)
    v[0]+=v[i];
  return v[0]+v[0]-v[v.size()-1];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  cout<<dfs(1,-1)<<endl;
  return 0;
}