/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-23 15:53:49                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 10                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11655
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
const long mod=1e5;
long way[N+2],len[N+2],vis[N+2],n;
vector<int>adj[N+2];
void dfs(int node)
{
  if(vis[node])return ;
  if(node==n)
  {
    way[node]=1;len[node]=1;
    return ;
  }
  vis[node]=1;
  for(auto x:adj[node])
  {
    dfs(x);way[node]=(way[node]+way[x])%mod;
    len[node]=(len[node]+len[x])%mod;
  }
  len[node]=(len[node]+way[node])%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int m;cin>>n>>m;
    for(int i=1;i<=n;i++)adj[i].clear();
    while(m--)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
    }
    memset(way,0,sizeof(way));
    memset(len,0,sizeof(len));
    memset(vis,0,sizeof(vis));
    dfs(1);
    cout<<"Case "<<++tc<<": "<<(len[1]-way[1]+mod)%mod<<" "<<way[1]<<endl;
  }
  return 0;
}