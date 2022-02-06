/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/05/2020 21:13                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 22800 KB                             
*  problem: https://codeforces.com/contest/1029/problem/E
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
const int N=1e6;
int ds[N+2];
vector<int>adj[N+2];
set<pair<int,int> >st;
void dfs(int node,int par,int d)
{
  if(d>2)st.insert({d,par});ds[node]=d;
  for(auto x:adj[node])
  {
    if(x!=par)dfs(x,node,d+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  int ans=0;dfs(1,-1,0);
  while(st.size())
  {
    pair<int,int>p=*st.rbegin();ans++;st.erase(p);
    for(auto x:adj[p.second])
    {
      if(st.find({ds[x],x})!=st.end())st.erase({ds[x],x});
    }
  }
  cout<<ans<<endl;
  return 0;
}