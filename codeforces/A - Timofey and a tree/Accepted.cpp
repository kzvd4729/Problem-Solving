/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/27/2018 10:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/763/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
vector<int>adj[N+2];
int cl[N+2],f,root;
void dfs(int node,int par)
{
 for(int i=0;i<adj[node].size();i++)
 {
  int xx=adj[node][i];if(xx==par)continue;
  dfs(xx,node);
  if(f)return ;
  if(cl[node]!=cl[xx])
  {
   f=1;root=node;
   return ;
  }
 }
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n;cin>>n;
 for(int i=1;i<n;i++)
 {
  int u,v;cin>>u>>v;
  adj[u].push_back(v);
  adj[v].push_back(u);
 }
 for(int i=1;i<=n;i++)cin>>cl[i];
 root=1;dfs(1,-1);f=0;int tmp=root;
 for(int i=0;i<adj[tmp].size();i++)
  dfs(adj[tmp][i],tmp);
 if(f)cout<<"NO"<<endl;
 else cout<<"YES"<<endl<<tmp<<endl;
 return 0;
}