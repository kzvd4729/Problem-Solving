/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/25/2019 20:20                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/875/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int vis[N+2],edg[N+2];
vector<vector<int> >adj[N+2];
int cal(int u)
{
  vis[u]=1;priority_queue<vector<int> >pq;
  for(auto x:adj[u])pq.push(x);int mx=0,ret=0;
  while(pq.size())
  {
    vector<int>v=pq.top();pq.pop();
    if(vis[v[1]])
    {
      if(!edg[v[2]])mx=max(mx,v[0]);
      continue;
    }
    ret+=v[0];vis[v[1]]=1;edg[v[2]]=1;
    for(auto x:adj[v[1]])
      pq.push(x);
  }
  return ret+mx;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({w,v,i});
    adj[v].push_back({w,u,i});
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    ans+=cal(i);
  }
  cout<<ans<<endl;
  return 0;
}