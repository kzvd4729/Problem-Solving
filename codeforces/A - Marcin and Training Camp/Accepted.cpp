/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/23/2019 20:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 15800 KB                             
*  problem: https://codeforces.com/contest/1229/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
bool vis[N+2];
long aa[N+2],bb[N+2],cost[N+2],ans;
map<long,long>mp,cnt;
vector<int>adj[N+2];
void dfs(int node)
{
  if(vis[node])return ;vis[node]=1;
  ans+=cost[node];
  for(auto x:adj[node])
    dfs(x);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)cin>>bb[i];
  for(int i=1;i<=n;i++)mp[aa[i]]+=bb[i],cnt[aa[i]]++;
  int id=0;vector<long>v,root;
  for(auto x:mp)
  {
    v.push_back(x.first);
    cost[++id]=x.second;
    if(cnt[x.first]>1)root.push_back(id);
  }
  for(int i=0;i<v.size();i++)
  {
    for(int j=0;j<v.size();j++)
    {
      if(i==j)continue;
      if((v[i]&v[j])==v[i])adj[j+1].push_back(i+1);
    }
  }
  for(auto x:root)dfs(x);cout<<ans<<endl;
  return 0;
}