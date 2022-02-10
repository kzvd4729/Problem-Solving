/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-06-06 23:59:29                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1108
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const int inf=1e8;
int dis[N+2],cnt[N+2],un[N+2];
int t,tc,n,m,vis[N+2];
vector<pair<int,int> >adj[N+2];
queue<int>q;
vector<int>ans,here;
int spfa(int sr)
{
  q.push(sr);
  dis[sr]=0;
  vis[sr]=1;
  cnt[sr]++;
  here.push_back(sr);
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
        }
        if(cnt[v]==0)here.push_back(v);
        cnt[v]++;
        if(cnt[v]>n)return 1;
      }
    }
  }
  return 0;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=0;i<n;i++)
      adj[i].clear();
    while(m--)
    {
      int u,v,w;
      cin>>u>>v>>w;
      adj[u].push_back({v,w});
    }
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    memset(un,0,sizeof(un));
    for(int i=0;i<n;i++)dis[i]=inf;
    ans.clear();
    for(int i=0;i<n;i++)
    {
      if(cnt[i]==0)
      {
        here.clear();
        if(spfa(i))
        {
          for(int i=0;i<here.size();i++)
            ans.push_back(here[i]);
        }
      }
    }
    sort(ans.begin(),ans.end());
    cout<<"Case "<<++tc<<": ";
    if(ans.size()==0)cout<<"impossible"<<endl;
    else
    {
      for(int i=0;i<ans.size();i++)
      {
        if(i!=0)cout<<" ";
        cout<<ans[i];
      }
      cout<<endl;
    }
  }
  return 0;
}