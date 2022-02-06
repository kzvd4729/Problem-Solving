/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/22/2018 23:51                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 1372 ms                                         memory_used: 54800 KB                             
*  problem: https://codeforces.com/contest/691/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,m,arr[N+2],u,v;
int vis[N+2];
vector<int>adj[N+2],pos,val;
void dfs(int node)
{
  pos.push_back(node);
  val.push_back(arr[node]);
  vis[node]=1;
  for(auto xx:adj[node])
  {
    if(vis[xx])continue;
    dfs(xx);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  for(int i=1;i<=m;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    pos.clear();
    val.clear();
    dfs(i);
    sort(val.begin(),val.end());
    reverse(val.begin(),val.end());
    sort(pos.begin(),pos.end());
    for(int i=0;i<val.size();i++)
      arr[pos[i]]=val[i];
  }
  for(int i=1;i<=n;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  return 0;
}