/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-19 15:41:53                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 228                                        memory_used (MB): 6.1                             
*  problem: https://vjudge.net/problem/LightOJ-1257
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e4;
int t,tc,n,u,v,w,mx,dis[N+2],ans[N+2],farthest;
vector<pair<int,int> >adj[N+2];
int dfs(int node,int pre,int cost)
{
  dis[node]=cost;
  for(int i=0;i<adj[node].size();i++)
  {
    pair<int,int>x=adj[node][i];
    if(x.first==pre)continue;
    dfs(x.first,node,cost+x.second);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<n;i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      u++,v++;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
    dfs(1,-1,0);
    mx=0;
    for(int i=1;i<=n;i++)
    {
      if(dis[i]>mx)
      {
        mx=dis[i];
        farthest=i;
      }
    }
    dfs(farthest,-1,0);
    mx=0;
    for(int i=1;i<=n;i++)
    {
      ans[i]=dis[i];
      if(dis[i]>mx)
      {
        mx=dis[i];
        farthest=i;
      }
    }
    dfs(farthest,-1,0);
    for(int i=1;i<=n;i++)
      ans[i]=max(ans[i],dis[i]);
    printf("Case %d:\n",++tc);
    for(int i=1;i<=n;i++)
      printf("%d\n",ans[i]);
  }
  return 0;
}