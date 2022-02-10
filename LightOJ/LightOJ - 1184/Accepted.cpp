/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-16 11:03:04                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 4                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1184
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
int t,tc,n,m,lft[102],rgt[102],dis[102];
vector<int>adj[102];
struct info
{
  int hg,ag,st;
}man[52],wman[52];
bool check(int r,int c)
{
  if(man[r].st!=wman[c].st)return false;
  if(abs(man[r].hg-wman[c].hg)>12)return false;
  if(abs(man[r].ag-wman[c].ag)>5)return false;
  return true;
}
bool bfs(void)
{
  queue<int>q;
  for(int i=1;i<=n;i++)
  {
    if(lft[i]==0)
    {
      dis[i]=0;
      q.push(i);
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
      q.push(rgt[v]);
    }
  }
  return dis[0]!=inf;
}
bool dfs(int u)
{
  if(!u)return true;
  for(int i=0;i<adj[u].size();i++)
  {
    int v=adj[u][i];
    if(dis[rgt[v]]!=dis[u]+1)continue;
    if(dfs(rgt[v]))
    {
      lft[u]=v;
      rgt[v]=u;
      return true;
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
      if(dfs(i))matching++;
    }
  }
  return matching;
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    for(int i=1;i<=100;i++)adj[i].clear();
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
      scanf("%d%d%d",&man[i].hg,&man[i].ag,&man[i].st);
    for(int i=1;i<=n;i++)
      scanf("%d%d%d",&wman[i].hg,&wman[i].ag,&wman[i].st);
    for(int i=1;i<=m;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if(check(i,j))
        {
          adj[i].push_back(m+j);
          adj[m+j].push_back(i);
        }
      }
    }
    n=m;
    printf("Case %d: %d\n",++tc,Hopcroft());
  }
  return 0;
}