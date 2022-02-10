/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-16 17:43:56                      
*  solution_verdict: Compilation Error                       language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1159
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=200;
const int con=50;
int t,tc;
char s[30],mat[30][30],cnt[30][30];
vector<int>adj[N+2];
bool bfs(void)
{
  queue<int>q;
  for(int i=1;i<=n;i++)
  {
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
      int v=adj[u][i];
      if(dis[rgt[v]]<=dis[u]+1)continue;
      dis[rgt[v]]=dis[u]+1;
      if(rgt[v])q.push(rgt[v]);
    }
  }
  return dis[0]!=inf;
}
bool dfs(int node)
{
  if(node==0)return true;
  for(int i=0;i<adj[node].size();i++)
  {
    int v=adj[node][i];
    if(dis[node]+1==dis[rgt[v]])
    {
      if(dfs(rgt[v]))
      {
        lft[node]=v;
        rgt[v]=node;
        return true;
      }
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
      if(dfs(i))
        matching++;
    }
  }
  return matching;
}
void create_graph(int x)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(mat[i][j]=='G')
      {
        for(int k=j+1;k<=n;k++)
        {
          if(mat[i][k]=='#')break;
          if(abs(k-j)+2>x)break;
          if(mat[i][k]=='H')
          {
            adj[cnt[i][j]].push_back(con+cnt[i][k]);
            adj[con+cnt[i][k]].push_back(cnt[i][j]);
          }
        }
        for(int k=j-1;k>=1;k--)
        {
          if(mat[i][k]=='#')break;
          if(abs(k-j)+2>x)break;
          if(mat[i][k]=='H')
          {
            adj[cnt[i][j]].push_back(con+cnt[i][k]);
            adj[con+cnt[i][k]].push_back(cnt[i][j]);
          }
        }
        for(int k=i-1;k>=1;k--)
        {
          if(mat[k][j]=='#')break;
          if(abs(k-i)+2>x)break;
          if(mat[k][j]=='H')
          {
            adj[cnt[i][j]].push_back(con+cnt[k][j]);
            adj[con+cnt[k][j]].push_back(cnt[i][j]);
          }
        }
        for(int k=i+1;k<=n;k++)
        {
          if(mat[k][j]=='#')break;
          if(abs(k-i)+2>x)break;
          if(mat[k][j]=='H')
          {
            adj[cnt[i][j]].push_back(con+cnt[k][j]);
            adj[con+cnt[k][j]].push_back(cnt[i][j]);
          }  
        }
      }
    }
  }
}
int main()
{
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
      scanf("%s",s);
      for(int j=1;j<=n;j++)
        mat[i][j]=s[j-1];
    }
    int lo=0,hi=1000,md;
    int cn=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        cnt[i][j]=++cn;
      }
    }
    while(hi-lo>3)
    {
      md=(lo+hi)/2;
      create_graph(md);

    }
    printf("Case %d: %d\n",++tc,Hopcroft());
  }
  return 0;
}