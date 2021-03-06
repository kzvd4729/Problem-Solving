/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/25/2019 16:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 778 ms                                          memory_used: 101200 KB                            
*  problem: https://codeforces.com/contest/117/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
int vis[N+2],f;
vector<int>adj[N+2],v;
void dfs(int node)
{
  if(vis[node]==2)return ;
  else if(vis[node]==1){f=1;return ;}
  else vis[node]=1,v.push_back(node);
  for(auto x:adj[node]){dfs(x);if(f)return ;}
  vis[node]=2;v.pop_back();
}
string ss[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;ss[i-1]=s;
    for(int j=1;j<=n;j++)
      if(s[j-1]=='1')adj[i].push_back(j);
  }
  for(int i=1;i<=n;i++)
    if(!vis[i]&&!f)dfs(i);
  int sz=v.size();
  for(int i=0;i<sz;i++)v.push_back(v[i]);
   for(int i=2;i<v.size();i++)
  {
    if(ss[v[i]-1][v[i-2]-1]=='1')
      cout<<v[i-2]<<" "<<v[i-1]<<" "<<v[i]<<endl,exit(0);
  }
  cout<<-1<<endl;
  return 0;
}