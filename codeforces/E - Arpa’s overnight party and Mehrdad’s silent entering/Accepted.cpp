/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/06/2018 22:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 343 ms                                          memory_used: 13500 KB                             
*  problem: https://codeforces.com/contest/742/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,color[N+N+2];
vector<int>adj[N+N+2];
pair<int,int>ed[N+2];
void dfs(int node,int cl)
{
  if(color[node]!=-1)
  {
    if(color[node]!=cl)
      cout<<-1<<endl,exit(0);
    else return ;
  }
  color[node]=cl;
  for(auto xx:adj[node])
    dfs(xx,cl^1);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<2*n;i+=2)
  {
    adj[i].push_back(i+1);
    adj[i+1].push_back(i);
  }
  for(int i=1;i<=n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    ed[i]={u,v};
  }
  memset(color,-1,sizeof(color));
  for(int i=1;i<=2*n;i++)
  {
    if(color[i]!=-1)continue;
    dfs(i,0);
  }
  for(int i=1;i<=n;i++)
    cout<<color[ed[i].first]+1<<" "<<color[ed[i].second]+1<<endl;
   return 0;
}