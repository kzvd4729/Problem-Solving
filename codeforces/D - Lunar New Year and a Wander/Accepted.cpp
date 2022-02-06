/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/09/2019 17:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 8000 KB                              
*  problem: https://codeforces.com/contest/1106/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int vis[N+2];
vector<int>adj[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  while(m--)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  set<int>st;st.insert(1);vector<int>ans;
  while(st.size())
  {
    int tp=*st.begin();st.erase(tp);
    if(vis[tp])continue;vis[tp]=1;
    ans.push_back(tp);
    for(auto x:adj[tp])
    {
      if(vis[x])continue;
      st.insert(x);
    }
  }
  for(auto x:ans)cout<<x<<" ";
    cout<<endl;
  return 0;
}