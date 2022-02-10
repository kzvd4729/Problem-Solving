/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-06-07 13:45:11                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 16                                         memory_used (MB): 1.8                             
*  problem: https://vjudge.net/problem/LightOJ-1019
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
const int inf=1e8;
int t,tc,n,m;
int dis[N+2],vis[N+2];
vector<pair<int,int> >adj[N+2];
int spfa(void)
{
  queue<int>q;
  memset(vis,0,sizeof(vis));
  for(int i=1;i<=n;i++)dis[i]=inf;
  q.push(1);
  dis[1]=0;
  vis[1]=1;

  while(q.size())
  {
    int u=q.front();
    q.pop();
    vis[u]=0;
    for(int i=0;i<adj[u].size();i++)
    {
      int v=adj[u][i].first;
      if(dis[u]+adj[u][i].second<dis[v])
      {
        dis[v]=dis[u]+adj[u][i].second;
        if(vis[v]==0)
        {
          vis[v]=1;
          q.push(v);
        }
      }
    }
  }
  return dis[n];
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
      int u,v,w;
      cin>>u>>v>>w;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
    int tmp=spfa();
    if(tmp==inf)cout<<"Case "<<++tc<<": Impossible"<<endl;
    else cout<<"Case "<<++tc<<": "<<tmp<<endl;
  }
  return 0;
}