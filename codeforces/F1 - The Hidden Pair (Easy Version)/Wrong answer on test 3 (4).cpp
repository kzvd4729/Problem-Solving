/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/21/2020 00:22                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1370/problem/F1
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e3;
vector<int>adj[N+2];
vector<int>v;
void dfs(int node,int par,int d)
{
  v.push_back(node);
  if(d==0)return;
  for(auto x:adj[node])
    if(x!=par)dfs(x,node,d-1);
}
void dfs2(int node,int par,int d)
{
  if(d==0)v.push_back(node);
  for(auto x:adj[node])
    if(x!=par)dfs2(x,node,d-1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<N+2;i++)adj[i].clear();v.clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);adj[v].push_back(u);
    }
    vector<int>lf;
    for(int i=1;i<=n;i++)if(adj[i].size()==1)lf.push_back(i);
     cout<<"? "<<n;
    for(int i=1;i<=n;i++)cout<<" "<<i;
    cout<<endl;
    int a,ds;cin>>a>>ds;
     int lo=0,hi=n,md;int nd=0;
    while(lo<hi)
    {
      md=(lo+hi)/2;v.clear();
      for(auto x:lf)dfs(x,-1,md);
      sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
       cout<<"? "<<v.size();assert(v.size());
      for(int i=0;i<v.size();i++)cout<<" "<<v[i];
      cout<<endl;
      int b;cin>>a>>b;
      if(b==ds)hi=md,nd=a;else lo=md+1;
    }
    v.clear();dfs2(nd,-1,ds);assert(nd);
    cout<<"? "<<v.size();assert(v.size());
    for(int i=0;i<v.size();i++)cout<<" "<<v[i];
    cout<<endl;
    int x,y;cin>>x>>y;
    cout<<"! "<<nd<<" "<<x<<endl;
  }
  return 0;
}