/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/07/2018 12:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 7400 KB                              
*  problem: https://codeforces.com/contest/688/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
vector<int>adj[N+2],ans[N+2];
int color[N+2];
void inv(void)
{
  cout<<"-1"<<endl;
  exit(0);
}
void dfs(int node,int h)
{
  if(!color[node])
    color[node]=(h%2+1);
  else
  {
    if(color[node]!=(h%2+1))inv();
    return ;
  }
  ans[h].push_back(node);
  for(auto x:adj[node])
    dfs(x,h+1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;set<int>x,y;
  while(m--)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++)
    if(!color[i])dfs(i,1);
  vector<int>s1,s2;
  for(int i=1;i<=n;i+=2)
    s1.insert(s1.end(),ans[i].begin(),ans[i].end());
  for(int i=2;i<=n;i+=2)
    s2.insert(s2.end(),ans[i].begin(),ans[i].end());
  cout<<s1.size()<<endl;
  for(auto x:s1)
    cout<<x<<" ";
  cout<<endl;
  cout<<s2.size()<<endl;
  for(auto x:s2)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}