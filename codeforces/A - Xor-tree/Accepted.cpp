/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/01/2019 16:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 6300 KB                              
*  problem: https://codeforces.com/contest/429/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
vector<int>adj[N+2],ans;
int iny[N+2],gol[N+2];
void dfs(int node,int par,int hg,int ev,int od)
{
  if(hg)
  {
    if(od)iny[node]^=1;
  }
  else
  {
    if(ev)iny[node]^=1;
  }
  if(iny[node]!=gol[node])
  {
    ans.push_back(node);
    if(hg)od^=1;else ev^=1;
  }
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,hg^1,ev,od);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++)cin>>iny[i];
  for(int i=1;i<=n;i++)cin>>gol[i];
  dfs(1,-1,0,0,0);cout<<ans.size()<<endl;
  for(auto x:ans)cout<<x<<" ";
    cout<<endl;
  return 0;
}