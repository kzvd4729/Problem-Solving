/****************************************************************************************
*  @author: kzvd4729                                         created: May/27/2018 21:40                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 389 ms                                          memory_used: 7400 KB                              
*  problem: https://codeforces.com/contest/981/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,u,v,cnt,last,root,f;
vector<int>adj[N+2];
void dfs(int node,int pre)
{
  for(auto x:adj[node])
  {
    if(x==pre)continue;
    dfs(x,node);
  }
  if(f==0)
  {
    last=node;
    f=1;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<n;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  root=1;
  for(int i=1;i<=n;i++)
    if(adj[i].size()==2)
      root=i;
  for(int i=1;i<=n;i++)
  {
    if(adj[i].size()>=3)
    {
      cnt++;
      root=i;
    }
  }
  if(cnt>1)cout<<"No"<<endl,exit(0);
  cout<<"Yes"<<endl;
  cout<<adj[root].size()<<endl;
  for(int i=0;i<adj[root].size();i++)
  {
    int x=adj[root][i];
    f=0;
    dfs(x,root);
    cout<<root<<" "<<last<<endl;
  }
  return 0;
}