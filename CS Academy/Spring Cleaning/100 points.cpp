/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: 100 points                              language: C++                                     
*  run_time: 191 ms                                          memory_used: 13.7 MB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int in[N+2],x,n,vis[N+2];
vector<int>adj[N+2],root;
void dfs(int node)
{
  vis[node]=1;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    dfs(x);
    cout<<node<<" "<<x<<endl;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    adj[i].push_back(x);
    in[x]++;
  }
  for(int i=1;i<=n;i++)if(!in[i])root.push_back(i);
  for(auto x:root)dfs(x);
  for(long i=1;i<=n;i++)
  {
    if(vis[i])continue;
    dfs(i);
  }
  return 0;
}