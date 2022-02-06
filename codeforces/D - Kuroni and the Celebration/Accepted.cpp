/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/03/2020 22:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 15900 KB                             
*  problem: https://codeforces.com/contest/1305/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int dg[N+2];
vector<int>adj[N+2];
set<int>st;
bool dfs(int node,int par,int tr)
{
  if(node==tr)return 1;
  bool ret=0;
  for(auto x:adj[node])
  {
    if(x!=par)ret|=dfs(x,node,tr);
  }
  return ret;
}
void del(int node,int par)
{
  if(st.find(node)!=st.end())st.erase(node);
  for(auto x:adj[node])
  {
    if(x!=par)del(x,node);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;dg[u]++,dg[v]++;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++)
  {
    if(dg[i]==1)st.insert(i);
  }
  int cnt=0;
  while(st.size()>1)
  {
    int a=-1,b=-1;
    a=*st.begin();st.erase(a);
    b=*st.begin();st.erase(b);
    cout<<"? "<<a<<" "<<b<<endl;
    int c;cin>>c;
    if(c==a||c==b||dg[c]==2)cout<<"! "<<c<<endl,exit(0);
    for(auto x:adj[c])
    {
      if(dfs(x,c,a))del(x,c);
      if(dfs(x,c,b))del(x,c);
    }
    dg[c]-=2;if(dg[c]==1)st.insert(c);
    if(dg[c]<=0)assert(0);
  }
  assert(0);
  //if(st.size()==0)assert(0);
  //if(st.size()==1)cout<<"! "<<*st.begin()<<endl,exit(0);
  //if(st.size())
  return 0;
}