/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-22 19:29:33                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 2                                          memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1149
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=100;
int t,tc,n,m,a[N+2],b[N+2];

const int H=N+N;
const int Inf=1e9;
int Lft[H+2],Rgt[H+2],Dis[H+2];
vector<int>Adj[H+2];
bool Bfs(void)
{
  queue<int>q;
  for(int i=1;i<=n;i++)
  {
    if(!Lft[i])
    {
      q.push(i);Dis[i]=0;
    }
    else Dis[i]=Inf;
  }
  Dis[0]=Inf;
  while(q.size())
  {
    int u=q.front();
    q.pop();
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
  if(node==0)return true;
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
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
      scanf("%d",&b[i]);
    for(int i=1;i<=n+m;i++)
      Adj[i].clear();
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(b[j]%a[i]==0)
          Adj[i].push_back(j);
      }
    }
    printf("Case %d: %d\n",++tc,Hopcroft());
  }
  return 0;
}