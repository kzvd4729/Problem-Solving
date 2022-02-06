/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/11/2018 19:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1020/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=2e9;
const int N=1e3;
int n,ans,vis[N+2];
vector<int>adj[N+2];
void dfs(int node)
{
  if(vis[node])
  {
    ans=node;
    return ;
  }
  vis[node]=1;
  for(auto xx:adj[node])
  {
    if(ans)return ;
    dfs(xx);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    adj[i].push_back(x);
  }
  for(int i=1;i<=n;i++)
  {
    memset(vis,0,sizeof(vis));
    ans=0;
    dfs(i);cout<<ans<<" ";
  }
  cout<<endl;
  return 0;
}