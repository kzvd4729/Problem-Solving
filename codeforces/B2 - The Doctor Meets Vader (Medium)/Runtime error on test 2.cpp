/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2019 17:06                        
*  solution_verdict: Runtime error on test 2                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1184/problem/B2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int dis[N+2][N+2],slc[N+2],sat[N+2],sfl[N+2];
int blc[N+2],bdf[N+2];
/*************** Hopcroft Karp *****************/
const int H=N;
const int Inf=1e9;
int Lft[H+2],Rgt[H+2],Dis[H+2];
vector<int>Adj[H+2];
bool Bfs(void)
{
  queue<int>q;
  for(int i=1;i<=N;i++)
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
    for(int i=1;i<=N;i++)
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
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      dis[i][j]=1e9;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    dis[u][v]=1;dis[v][u]=1;
  }
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
  int s,b,k,h;cin>>s>>b>>k>>h;
  for(int i=1;i<=s;i++)
    cin>>slc[i]>>sat[i]>>sfl[i];
  for(int i=1;i<=b;i++)
    cin>>blc[i]>>bdf[i];
   for(int i=1;i<=s;i++)
  {
    for(int j=1;j<=b;j++)
    {
      if(dis[slc[i]][blc[j]]<=sfl[i]&&sat[i]>=bdf[j])
        Adj[i].push_back(j);
    }
  }
  long one=(Hopcroft()*1LL)*(k*1LL);
  long two=(s*1LL)*(h*1LL);
  cout<<min(one,two)<<endl;
  return 0;
}