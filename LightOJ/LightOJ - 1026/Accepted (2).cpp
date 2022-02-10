/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-23 00:17:32                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 264                                        memory_used (MB): 7.3                             
*  problem: https://vjudge.net/problem/LightOJ-1026
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
int n,u,v,x,t,tc,pid,tim;
int vis[N+2],low[N+2],desc[N+2];
char s[12];
pair<int,int>p[10*N+2];
vector<int>adj[N+2];
void dfs(int node,int pre)
{
  desc[node]=low[node]=++tim;
  vis[node]=1;
  for(int i=0;i<adj[node].size();i++)
  {
    int next=adj[node][i];
    if(!vis[next])
    {
      dfs(next,node);
      low[node]=min(low[node],low[next]);
      if(low[next]>desc[node])
      {
        int uu=next;
        int vv=node;
        if(uu>vv)swap(uu,vv);
        p[++pid]={uu,vv};
      }
    }
    else if(next!=pre)
      low[node]=min(low[node],desc[next]);
  }
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      adj[i].clear();
    for(int i=0;i<n;i++)
    {
      scanf("%d",&u);
      scanf("%s",&s);
      x=0;
      for(int j=1;j<strlen(s)-1;j++)
        x=x*10+s[j]-'0';
      while(x--)
      {
        scanf("%d",&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
    }
    pid=0,tim=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
    {
      if(vis[i])continue;
      dfs(i,-1);
    }
    printf("Case %d:\n",++tc);
    printf("%d critical links\n",pid);
    sort(p+1,p+pid+1);
    for(int i=1;i<=pid;i++)
      printf("%d - %d\n",p[i].first,p[i].second);
  }
  return 0;
}