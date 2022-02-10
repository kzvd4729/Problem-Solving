/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-12 20:05:56                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 536                                        memory_used (MB): 20.6                            
*  problem: https://vjudge.net/problem/LightOJ-1128
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int t,n,q,pi,cost[N+2],sp[N+2][20];
int level[N+2],parent[N+2],tc;
vector<int>adj[N+2];
void dfs(int node,int par,int h)
{
  level[node]=h;parent[node]=par;
  for(int i=0;i<adj[node].size();i++)
  {
    int xx=adj[node][i];
    if(xx==par)continue;
    dfs(xx,node,h+1);
  }
}
void sparse(void)
{
  memset(sp,-1,sizeof(sp));
  for(int i=0;i<n;i++)
    sp[i][0]=parent[i];
  for(int j=1;j<=18;j++)
  {
    for(int i=0;i<n;i++)
    {
      if(sp[i][j-1]==-1)continue;
      sp[i][j]=sp[sp[i][j-1]][j-1];
    }
  }
}
void query(int node,int vl)
{
  for(int i=18;i>=0;i--)
  {
    if(sp[node][i]==-1)continue;
    if(cost[sp[node][i]]>=vl)node=sp[node][i];
  }
  printf("%d\n",node);
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&n,&q);cost[0]=1;
    for(int i=0;i<n;i++)adj[i].clear();
    for(int i=1;i<n;i++)
    {
      scanf("%d%d",&pi,&cost[i]);
      adj[pi].push_back(i);
    }
    dfs(0,-1,0);sparse();
    printf("Case %d:\n",++tc);
    while(q--)
    {
      int node,vl;scanf("%d%d",&node,&vl);
      query(node,vl);
    }
  }
  return 0;
}