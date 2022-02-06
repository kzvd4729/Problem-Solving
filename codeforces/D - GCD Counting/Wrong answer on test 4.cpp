/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/11/2019 22:05                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 6400 KB                              
*  problem: https://codeforces.com/contest/1101/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],ans;
pair<int,int>dis[N+2][2];
vector<int>adj[N+2];
int dfs(int node,int par)
{
  priority_queue<pair<int,int> >pq;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    int xx=dfs(x,node);
    if(__gcd(aa[node],aa[x])>1)
      pq.push({xx+1,x});
  }
   if(aa[node]>1)pq.push({1,node});
  else pq.push({0,node});
  pq.push({0,-1});
   dis[node][0]=pq.top();pq.pop();
  dis[node][1]=pq.top();
   ans=max(ans,dis[node][0].first);
   return dis[node][0].first;
}
void dds(int node,int par,int ds)
{
  ans=max(ans,ds);
  for(auto x:adj[node])
  {
    if(x==par)continue;
     if(__gcd(aa[node],aa[x])>1)
    {
      if(x==dis[node][0].second)
        dds(x,node,max(dis[node][1].first,ds)+1);
      else dds(x,node,max(dis[node][0].first,ds)+1);
    }
    else
    {
      if(aa[x]>1)dds(x,node,1);
      else dds(x,node,0);
    }
  }
}  
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1);
  if(aa[1]>1)dds(1,-1,1);
  else dds(1,-1,0);
  cout<<ans<<endl;
  return 0;
}