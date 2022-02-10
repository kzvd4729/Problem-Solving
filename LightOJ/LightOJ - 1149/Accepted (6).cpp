/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-15 19:22:27                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 4                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1149
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=100;
const int inf=1e9;
int t,tc,n,m,a[N+2],b[N+2],lft[N+N+2],rgt[N+N+2];
int dis[N+N+2];
vector<int>adj[N+N+2];
bool bfs(void)
{
  queue<int>q;
  for(int i=1;i<=n;i++)
  {
    if(!lft[i])
    {
      q.push(i);
      dis[i]=0;
    }
    else dis[i]=inf;
  }
  dis[0]=inf;
  while(q.size())
  {
    int u=q.front();
    q.pop();
    for(int i=0;i<adj[u].size();i++)
    {
      int v=adj[u][i];
      if(dis[rgt[v]]<=dis[u]+1)continue;
      dis[rgt[v]]=dis[u]+1;
      if(rgt[v])q.push(rgt[v]);
    }
  }
//  for(int i=0;i<=n;i++)
//    cout<<dis[i]<<" ";
//  cout<<endl;
//  getchar();
//  getchar();
  return dis[0]!=inf;
}
bool dfs(int node)
{
  if(node==0)return true;
  for(int i=0;i<adj[node].size();i++)
  {
    int v=adj[node][i];
    if(dis[node]+1==dis[rgt[v]])
    {
      if(dfs(rgt[v]))
      {
        lft[node]=v;
        rgt[v]=node;
        return true;
      }
    }
  }
  return false;
}
int Hopcroft(void)
{
  memset(lft,0,sizeof(lft));
  memset(rgt,0,sizeof(rgt));
  int matching=0;
  while(bfs())
  {
    for(int i=1;i<=n;i++)
    {
      if(dis[i])continue;
      if(dfs(i))
      {
        //cout<<i<<endl;
        matching++;
      }
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
      adj[i].clear();
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(b[j]%a[i]==0)
        {
          adj[i].push_back(n+j);
          adj[n+j].push_back(i);
        }
      }
    }
    printf("Case %d: %d\n",++tc,Hopcroft());
  }
  return 0;
}