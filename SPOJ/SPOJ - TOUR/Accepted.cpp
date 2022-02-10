/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-11 00:01:46                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 360                                        memory_used (MB): 15.4                            
*  problem: https://vjudge.net/problem/SPOJ-TOUR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int n,m,x,vis[N+2],t;
vector<int>adj[N+2];
void dfs(int node)
{
  if(vis[node])return ;
  vis[node]=1;
  for(int i=0;i<adj[node].size();i++)
    dfs(adj[node][i]);
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
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&m);
      while(m--)
      {
        scanf("%d",&x);
        adj[x].push_back(i);
      }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
      memset(vis,0,sizeof(vis));
      dfs(i);
      int cnt=0;
      for(int i=1;i<=n;i++)
        cnt+=vis[i];
      if(cnt==n)ans++;
    }
    printf("%d\n",ans);
  }
  return 0;
}