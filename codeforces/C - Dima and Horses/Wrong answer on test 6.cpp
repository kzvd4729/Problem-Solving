/****************************************************************************************
*  @author: kzvd4729                                         created: May/13/2019 17:22                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 60 ms                                           memory_used: 15800 KB                             
*  problem: https://codeforces.com/contest/273/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int pr[N+2],n;
vector<int>adj[N+2];
bool ok(int id,vector<int>v)
{
  for(auto x:v)
    pr[x]=id;
  int f=1;
  for(auto x:v)
  {
    int cnt=0;
    for(auto z:adj[x])
      if(pr[z]==id)cnt++;
    if(cnt>1)f=0;
  }
  for(auto x:v)
    pr[x]=0;
  return f;
}
void dfs(int node)
{
  if(node>n)
  {
    for(int i=1;i<=n;i++)
    {
      if(!pr[i])assert(0);
      cout<<pr[i]-1;
    }
    cout<<endl;exit(0);
  }
  if(pr[node])dfs(node+1);
  vector<int>v;v.push_back(node);
  for(auto x:adj[node])
    if(!pr[x])v.push_back(x);
  int x=v.size();
  for(int i=0;i<(1<<x);i++)
  {
    vector<int>on,tw;
    for(int j=0;j<x;j++)
    {
      if(i&(1<<j))on.push_back(v[j]);
      else tw.push_back(v[j]);
    }
    if(ok(1,on)&&ok(2,tw))
    {
      for(auto x:on)pr[x]=1;
      for(auto x:tw)pr[x]=2;
      dfs(node+1);
      for(auto x:on)pr[x]=0;
      for(auto x:tw)pr[x]=0;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m;
  while(m--)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  return 0;
}