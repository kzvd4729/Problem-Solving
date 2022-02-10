/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-22 19:33:43                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 208                                        memory_used (MB): 2.5                             
*  problem: https://vjudge.net/problem/LightOJ-1403
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const int inf=1e8;
int t,tc,n,m;
/*************** Hopcroft Karp *****************/
const int H=N;
const int Inf=1e9;
int Lft[H+2],Rgt[H+2],Dis[H+2];
vector<int>Adj[H+2];
bool Bfs(void)
{
  queue<int>q;
  for(int i=1;i<=n;i++)
  {
    if(!Lft[i])q.push(i),Dis[i]=0;
    else Dis[i]=Inf;
  }
  Dis[0]=Inf;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(int i=0;i<Adj[u].size();i++)
    {
      int v=Adj[u][i];
      if(Dis[Rgt[v]]<=Dis[u]+1)continue;
      Dis[Rgt[v]]=Dis[u]+1;
      if(Rgt[v])q.push(Rgt[v]);
    }
  }
  return Dis[0]!=Inf;
}
bool Dfs(int node)
{
  if(!node)return true;
  for(int i=0;i<Adj[node].size();i++)
  {
    int v=Adj[node][i];
    if(Dis[node]+1==Dis[Rgt[v]])
    {
      if(Dfs(Rgt[v]))
      {
        Lft[node]=v;Rgt[v]=node;
        return true;
      }
    }
  }
  return false;
}
int Hopcroft(void)
{
  memset(Lft,0,sizeof(Lft));
  memset(Rgt,0,sizeof(Rgt));
  int matching=0;
  while(Bfs())
  {
    for(int i=1;i<=n;i++)
    {
      if(Dis[i])continue;
      if(Dfs(i))matching++;
    }
  }
  return matching;
}
///////////////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      Adj[i].clear();
    while(m--)
    {
      int u,v;
      cin>>u>>v;
      Adj[u].push_back(v);
    }
    cout<<"Case "<<++tc<<": "<<n-Hopcroft()<<endl;
  }
  return 0;
}