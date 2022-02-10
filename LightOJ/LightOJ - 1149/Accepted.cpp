/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-09-09 20:33:13                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 2                                          memory_used (MB): 2.9                             
*  problem: https://vjudge.net/problem/LightOJ-1149
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;

/*
complexity E*sqrt(V)
*/
struct hopcroft
{
  int a,b;//number of nodes in left and right side both numbered from 1.
  vector<int>lft,rgt,dis;
  vector<vector<int> >adj;
  void clean()
  {
    lft.resize(a+1),rgt.resize(b+1),dis.resize(a+1);
    adj.resize(a+1);
    for(int i=0;i<=a;i++)
      lft[i]=0,adj[i].clear();
    for(int i=0;i<=b;i++)
      rgt[i]=0;
  }
  bool bfs(void)
  {
    queue<int>q;
    for(int i=1;i<=a;i++)
    {
      if(!lft[i])q.push(i),dis[i]=0;
      else dis[i]=inf;
    }
    dis[0]=inf;
    while(q.size())
    {
      int u=q.front();q.pop();
      for(auto v:adj[u])
      {
        if(dis[rgt[v]]<=dis[u]+1)continue;
        dis[rgt[v]]=dis[u]+1;
        if(rgt[v])q.push(rgt[v]);
      }
    }
    return dis[0]!=inf;
  }
  bool dfs(int u)
  {
    if(!u)return true;
    for(auto v:adj[u])
    {
      if(dis[u]+1==dis[rgt[v]])
      {
        if(dfs(rgt[v]))
        {
          lft[u]=v;rgt[v]=u;return true;
        }
      }
    }
    return false;
  }
  int matching(void)
  {
    int match=0;
    while(bfs())
    {
      for(int i=1;i<=a;i++)
      {
        if(dis[i])continue;
        if(dfs(i))match++;
      }
    }
    return match;
  }
}h;

int a[N+2],b[N+2];
int main()
{
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d",&a[i]);
    int m;scanf("%d",&m);
    for(int i=1;i<=m;i++)
      scanf("%d",&b[i]);

    h.a=n,h.b=m;h.clean();

    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(b[j]%a[i]==0)
          h.adj[i].push_back(j);
      }
    }
    printf("Case %d: %d\n",++tc,h.matching());
  }
  return 0;
}