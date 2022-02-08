/****************************************************************************************
*  @author: kzvd4729                                         created: 07-04-2019 18:42:44                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.27 sec                                        memory_used: 24.6M                                
*  problem: https://www.codechef.com/APRIL19A/problems/SUBREM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],x;
vector<int>adj[N+2];
long dfs(int node,int par)
{
  long sm=aa[node];
  for(auto x:adj[node])
  {
    if(x==par)continue;
    sm+=dfs(x,node);
  }
  return max(sm,-x*1LL);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n>>x;
    for(int i=1;i<=n;i++)
      cin>>aa[i],adj[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    cout<<dfs(1,-1)<<endl;
  }
  return 0;
}