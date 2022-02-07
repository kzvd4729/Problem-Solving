/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-06-06 23:03:14                      
*  solution_verdict: Presentation error                      language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-1171
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e8;
int t,tc,n,sr,ds,vis[303],dis[303];
int m,cnt[303];
vector<pair<int,int> >adj[303];
int spfa(void)
{
  memset(vis,0,sizeof(vis));
  memset(cnt,0,sizeof(cnt));
  for(int i=0;i<n;i++)dis[i]=inf;
  queue<int>q;
  q.push(sr);
  dis[sr]=0;
  vis[sr]=1;
  cnt[sr]=1;
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
          q.push(v);
          vis[v]=1;
          cnt[v]++;
          if(cnt[v]>n)return inf;
        }
      }
    }
//    for(int i=0;i<n;i++)
//      cout<<dis[i]<<" ";
//    cout<<endl;
  }
  return dis[ds];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>sr>>ds;
    cin>>m;
    for(int i=0;i<n;i++)
      adj[i].clear();
    while(m--)
    {
      int u,v,w;
      cin>>u>>v>>w;
      adj[u].push_back({v,w});
      //adj[v].push_back({u,w});
    }
    int tmp=spfa();
    if(tmp==inf)cout<<"infinity"<<endl;
    else cout<<tmp<<endl;
  }
  return 0;
}