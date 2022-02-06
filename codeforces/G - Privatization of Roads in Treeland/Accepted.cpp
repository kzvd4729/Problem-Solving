/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/19/2019 22:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 451 ms                                          memory_used: 54200 KB                             
*  problem: https://codeforces.com/contest/1141/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int bad[N+2],cl,ans[N+2];
vector<int>adj[N+2];
pair<int,int>pp[N+2];
map<pair<int,int>,int>mp;
void dfs(int node,int par,int c)
{
 int now=0;
 for(auto x:adj[node])
 {
  if(x==par)continue;
  now=(now+1)%cl;if(!now)now=cl;
  if(now==c)now=(now+1)%cl;
  if(!now)now=cl;
  int u=node,v=x;if(u>v)swap(u,v);
  ans[mp[{u,v}]]=now;
  dfs(x,node,now);
 }
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n,k;cin>>n>>k;
 for(int i=1;i<n;i++)
 {
  int u,v;cin>>u>>v;
  adj[u].push_back(v);
  adj[v].push_back(u);
  if(u>v)swap(u,v);mp[{u,v}]=i;
 }
 for(int i=1;i<=n;i++)
  pp[i]={adj[i].size(),i};
 sort(pp+1,pp+n+1);cl=pp[n-k].first;
 cout<<cl<<endl;dfs(pp[n-k].second,-1,0);
 for(int i=1;i<n;i++)
  cout<<ans[i]<<" ";
 cout<<endl;
 return 0;
}