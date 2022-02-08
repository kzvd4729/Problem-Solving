/****************************************************************************************
*  @author: kzvd4729                                         created: 14-12-2018 20:20:24                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.42 sec                                        memory_used: 57M                                  
*  problem: https://www.codechef.com/DEC18A/problems/DLDAG
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;int out[N+2],rt,vis[N+2];
vector<int>adj[N+2];
void dfs(int node)
{
  vis[node]=1;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    dfs(x);
  }
  cout<<1<<" "<<node<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  while(m--)
  {
    int u,v;cin>>u>>v;out[v]++;
    adj[u].push_back(v);
  }
  cout<<n<<endl;
  for(int i=1;i<=n;i++)
  {
    if(out[i]==0)dfs(i);
  }
  return 0;
}