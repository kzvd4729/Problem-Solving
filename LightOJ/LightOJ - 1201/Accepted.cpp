/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-19 15:40:12                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 12                                         memory_used (MB): 1.9                             
*  problem: https://vjudge.net/problem/LightOJ-1201
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
const int N=1e3;
int t,tc,n,m,u,v,lft[N+2],rgt[N+2],dis[N+2],tru[N+2];
vector<int>adj[N+2];
bool bfs(void)
{
  queue<int>q;
  for(int i=1;i<=n;i++)
  {
    if(tru[i]==0||tru[i]==-1)
    {
      dis[i]=inf;
      continue;
    }
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
      v=adj[u][i];
      if(dis[rgt[v]]!=inf)continue;
      dis[rgt[v]]=dis[u]+1;
      if(rgt[v])q.push(rgt[v]);
    }
  }
  return dis[0]!=inf;
}
bool dfs(int u)
{
  if(u==0)return true;
  for(int i=0;i<adj[u].size();i++)
  {
    int v=adj[u][i];
    if(dis[rgt[v]]==dis[u]+1&&dfs(rgt[v]))
    {
      rgt[v]=u;
      lft[u]=v;
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
      if(tru[i]==0||tru[i]==-1||dis[i])continue;
      if(dfs(i))
        matching++;
    }
  }
  return matching;
}
void bicolor(int node,int pre,int color)
{
  tru[node]=color;
  for(int i=0;i<adj[node].size();i++)
  {
    int v=adj[node][i];
    if(v==pre)continue;
    bicolor(v,node,color^1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)adj[i].clear();
    while(m--)
    {
      scanf("%d%d",&u,&v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    memset(tru,-1,sizeof(tru));
    for(int i=1;i<=n;i++)
      if(tru[i]==-1)bicolor(i,-1,0);
    printf("Case %d: %d\n",++tc,n-Hopcroft());
  }
  return 0;
}