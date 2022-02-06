/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/17/2019 12:37                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/1174/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
vector<int>adj[N+2];
bitset<N+2>one,two;
void dfs(int node,int par,int d)
{
  if(d==0)two[node]=1;
  if(d<=0)return ;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,d-1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int>v;for(int i=1;i<=n;i++)v.push_back(i);
  shuffle(v.begin(),v.end(),rng);one.set();
  for(int i=0;i<min(n,36);i++)
  {
    cout<<"d "<<v[i]<<endl;int d;cin>>d;
    two.reset();dfs(v[i],-1,d);
    one&=two;
  }
  for(int i=1;i<=n;i++)
    if(one[i])cout<<"! "<<i<<endl,exit(0);
  return 0;
}