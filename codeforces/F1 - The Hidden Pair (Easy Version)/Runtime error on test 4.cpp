/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/21/2020 01:00                        
*  solution_verdict: Runtime error on test 4                 language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
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
vector<int>v;int dst[N+2];
void dfs(int node,int par,int d)
{
  dst[node]=d;
  for(auto x:adj[node])
    if(x!=par)dfs(x,node,d+1);
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
    dfs(1,-1,1);vector<int>tmp;
    for(int i=1;i<=n;i++)tmp.push_back(i);
    sort(tmp.begin(),tmp.end(),[&](int a,int b){
      return dst[a]<dst[b];
    });
     //for(int i=0;i<tmp.size();i++)cout<<tmp[i]<<" ";cout<<endl;
    cout<<"? "<<n;
    for(int i=1;i<=n;i++)cout<<" "<<i;
    cout<<endl;
    int a,ds;cin>>a>>ds;
      int lo=0,hi=n-1,md;int nd=0;
    while(lo<hi)
    {
      md=(lo+hi)/2;
       cout<<"? "<<hi-md+1;
      for(int i=md;i<=hi;i++)cout<<" "<<tmp[i];
      cout<<endl;
      int b;cin>>a>>b;
      if(b==ds)lo=md+1,nd=a;else hi=md;
    }
    v.clear();dfs2(nd,-1,ds);assert(nd);
    assert(v.size());cout<<"? "<<v.size();
    for(int i=0;i<v.size();i++)cout<<" "<<v[i];
    cout<<endl;
    int x,y;cin>>x>>y;
    cout<<"! "<<nd<<" "<<x<<endl;string s;cin>>s;
  }
  return 0;
}