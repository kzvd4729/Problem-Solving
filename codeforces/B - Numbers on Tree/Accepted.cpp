/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/05/2020 20:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 108 ms                                          memory_used: 21900 KB                             
*  problem: https://codeforces.com/contest/1286/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3,inf=1e9;
int cnt[N+2],ans[N+2];
vector<int>adj[N+2];
vector<pair<int,int> >v[N+2];
void dfs(int node)
{
  for(auto x:adj[node])
  {
    dfs(x);
    for(auto z:v[x])v[node].push_back(z);
  }
  if(cnt[node]>v[node].size())cout<<"NO\n",exit(0);
  if(v[node].size()==0)
  {
    v[node].push_back({1,node});return ;
  }
  sort(v[node].begin(),v[node].end());
   for(int i=0;i<v[node].size();i++)
  {
    v[node][i].first=i+1;
    if(i>=cnt[node])v[node][i].first++;
  }
  v[node].push_back({cnt[node]+1,node});
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int root;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x>>cnt[i];
    if(x)adj[x].push_back(i);else root=i;
  }
  dfs(root);cout<<"YES\n";
  for(auto x:v[root])ans[x.second]=x.first;
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
  return 0;
}