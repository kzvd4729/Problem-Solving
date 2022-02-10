/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-31 21:18:46                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 292                                        memory_used (MB): 2                               
*  problem: https://vjudge.net/problem/LightOJ-1403
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const int inf=1e8;
int t,tc,n,m;
int lft[N+2],rgt[N+2],dis[N+2];
vector<int>adj[N+2];
bool bfs(void)
{
  queue<int>q;
  for(int i=1;i<=n;i++)
  {
    if(!lft[i])
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
      if(dis[rgt[v]]==inf)
      {
        dis[rgt[v]]=dis[u]+1;
        if(rgt[v])q.push(rgt[v]);
      }
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
  int matching=0;
  memset(lft,0,sizeof(lft));
  memset(rgt,0,sizeof(rgt));
  while(bfs())
  {
    for(int i=1;i<=n;i++)
    {
      if(!dis[i]&&dfs(i))
        matching++;
    }
  }
  return matching;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      adj[i].clear();
    while(m--)
    {
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
    }
    cout<<"Case "<<++tc<<": "<<n-Hopcroft()<<endl;
  }
  return 0;
}