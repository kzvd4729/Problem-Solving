/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/25/2018 23:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 10200 KB                             
*  problem: https://codeforces.com/contest/1056/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
vector<int>adj[N+2],v;
int dfs(int node,int par)
{
  int here=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    here+=dfs(x,node);
  }
  if(!here)here=1;
  v.push_back(here);
  return here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=2;i<=n;i++)
  {
    int x;cin>>x;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }
  dfs(1,-1);
  sort(v.begin(),v.end());
  for(int i=0;i<n;i++)
    cout<<v[i]<<" ";
  cout<<endl;
  return 0;
}