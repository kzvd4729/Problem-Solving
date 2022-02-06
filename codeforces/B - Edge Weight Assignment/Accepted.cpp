/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/13/2020 09:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 22000 KB                             
*  problem: https://codeforces.com/contest/1338/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int cl[N+2];
vector<int>adj[N+2];
void color(int node,int par,int c)
{
  cl[node]=c;
  for(auto x:adj[node])
    if(x!=par)color(x,node,c^1);
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
  color(1,-1,0);int mn=3,mx=n-1;
  set<int>st;
  for(int i=1;i<=n;i++)
    if(adj[i].size()==1)st.insert(cl[i]);
  if(st.size()==1)mn=1;
  for(int i=1;i<=n;i++)
  {
    int cnt=0;
    for(auto x:adj[i])
      if(adj[x].size()==1)cnt++;
    if(cnt)mx-=(cnt-1);
  }
  cout<<mn<<" "<<mx<<endl;
  return 0;
}