/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/02/2021 20:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 950 ms                                          memory_used: 105500 KB                            
*  problem: https://codeforces.com/contest/1476/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 const int N=1e6,inf=1e9;
string p[N+2],s[N+2];int x[N+2];
vector<int>v[N+2],ad[N+2];
  vector<int>topo_sorted;
int tp_vis[N+2];
void Topo_sort(int node)
{
  tp_vis[node]=1;
  for(auto x:ad[node])
  {
    if(tp_vis[x])continue;
    Topo_sort(x);
  }
  topo_sorted.push_back(node);
}
vector<int>Topological_Sort(int n)
{
  for(int i=1;i<=n;i++)
  {
    if(tp_vis[i])continue;
    Topo_sort(i);
  }
  reverse(topo_sorted.begin(),topo_sorted.end());
  return topo_sorted;
}
int vs[N+2];
void dfs(int nd)
{
  if(vs[nd]==2)return ;
  if(vs[nd]==1)cout<<"NO"<<endl,exit(0);
  vs[nd]=1;
  for(auto x:ad[nd])dfs(x);
   vs[nd]=2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m,k;cin>>n>>m>>k;
  map<string,int>mp;
  for(int i=1;i<=n;i++)
  {
    cin>>p[i];
    mp[p[i]]=i;
  }
  for(int i=1;i<=m;i++)
  {
    cin>>s[i]>>x[i];
    int f=0;
    for(int msk=0;msk<(1<<k);msk++)
    {
      string t=s[i];
      for(int j=0;j<k;j++)
        if(msk&(1<<j))t[j]='_';
       if(mp.count(t))
        v[i].push_back(mp[t]);
    }
    for(auto u:v[i])
    {
      if(u==x[i])f=1;
      else ad[x[i]].push_back(u);
    }
    if(f==0)cout<<"NO"<<endl,exit(0);
  }
  for(int i=1;i<=n;i++)dfs(i);
   vector<int>v=Topological_Sort(n);
  cout<<"YES"<<endl;
  for(auto x:v)cout<<x<<" ";cout<<endl;
   return 0;
}