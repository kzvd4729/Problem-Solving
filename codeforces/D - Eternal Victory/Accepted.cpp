/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/21/2019 02:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 14600 KB                             
*  problem: https://codeforces.com/contest/61/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
vector<pair<int,int> >adj[N+2];
int mx;
void dfs(int node,int par,int cs)
{
  mx=max(mx,cs);
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    dfs(x.first,node,cs+x.second);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int sm=0;
  for(int i=1;i<n;i++)
  {
    int u,v,w;cin>>u>>v>>w;sm+=w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  dfs(1,-1,0);long ans=2LL*sm-mx;
  cout<<ans<<endl;
    return 0;
}