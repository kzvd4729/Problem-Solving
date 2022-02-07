/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-02 22:43:01                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10004
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,u,v,colour[202],f;
vector<int>adj[202];
void dfs(int node,int color)
{
  if(colour[node]!=-1)
  {
    if(colour[node]!=color)
      f=1;
    return ;
  }
  colour[node]=color;
  for(auto x:adj[node])
    dfs(x,color^1);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while(cin>>n)
  {
    if(!n)break;
    cin>>m;
    for(int i=0;i<n;i++)adj[i].clear();
    memset(colour,-1,sizeof(colour));
    while(m--)
    {
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    f=0;
    dfs(0,0);
    if(f==0)cout<<"BICOLORABLE."<<endl;
    else cout<<"NOT BICOLORABLE."<<endl;
  }
  return 0;
}