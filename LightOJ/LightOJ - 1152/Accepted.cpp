/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-16 15:49:21                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1152
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const int inf=1e9;
int t,tc,tt,vis[22][22],cnt[22][22],n,m;
int lft[N+2],rgt[N+2],dis[N+2];
char s[22],mat[22][22];
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};
vector<int>adj[N+2];
void dfs(int r,int c,int cl)
{
  if(r>n||r<1||c>m||c<1||vis[r][c]!=-1||mat[r][c]=='o')return ;
  vis[r][c]=cl;
  for(int i=0;i<4;i++)
    dfs(r+dr[i],c+dc[i],cl^1);
}
bool bfs(void)
{
  queue<int>q;
  for(int i=1;i<=n;i++)
  {
    if(lft[i]==0)
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
      if(dis[rgt[v]]<=dis[u]+1)continue;
      dis[rgt[v]]=dis[u]+1;
      q.push(rgt[v]);
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
  memset(lft,0,sizeof(lft));
  memset(rgt,0,sizeof(rgt));
  int matching=0;
  while(bfs())
  {
    for(int i=1;i<=n;i++)
    {
      if(dis[i])continue;
      if(dfs(i))matching++;
    }
  }
  return matching;
}
int main()
{
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%d%d",&n,&m);
    int nn=n,mm=m;
    tt=0;
    for(int i=1;i<=n;i++)
    {
      scanf("%s",s);
      for(int j=1;j<=m;j++)
      {
        mat[i][j]=s[j-1];
        if(mat[i][j]=='*')tt++;
      }
    }
    memset(vis,-1,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(mat[i][j]=='o'||vis[i][j]!=-1)continue;
        dfs(i,j,0);
      }
    }
    int con=400;
    n=0;
    for(int i=1;i<=nn;i++)
    {
      for(int j=1;j<=mm;j++)
      {
        if(vis[i][j]==0)
          cnt[i][j]=++n;
        else if(vis[i][j]==1)
          cnt[i][j]=++con;
      }
    }
//    for(int i=0;i<=nn+1;i++)
//    {
//      for(int j=0;j<=mm+1;j++)
//      {
//        cout<<cnt[i][j]<<" ";
//      }
//      cout<<endl;
//    }
    for(int i=1;i<=N;i++)adj[i].clear();
    for(int i=1;i<=nn;i++)
    {
      for(int j=1;j<=mm;j++)
      {
        if(vis[i][j]==0)
        {
          for(int k=0;k<4;k++)
          {
            if(vis[i+dr[k]][j+dc[k]]==1)
              adj[cnt[i][j]].push_back(cnt[i+dr[k]][j+dc[k]]);
          }
        }
        if(vis[i][j]==1)
        {
          for(int k=0;k<4;k++)
          {
            if(vis[i+dr[k]][j+dc[k]]==0)
              adj[cnt[i][j]].push_back(cnt[i+dr[k]][j+dc[k]]);
          }
        }
//        if(vis[i][j]==0||vis[i][j]==1)
//        {
//          for(int k=0;k<4;k++)
//          {
//            if(vis[i+dr[k]][j+dc[k]]==vis[i][j]^1)
//              adj[cnt[i][j]].push_back(cnt[i+dr[k]][j+dc[k]]);
//          }
//        }
      }
    }
//    cout<<endl<<endl;
//    for(int i=1;i<=4;i++)
//    {
//      for(auto x:adj[i])cout<<x<<" ";
//      cout<<endl;
//    }
//    cout<<tt<<" "<<Hopcroft()<<endl;
    printf("Case %d: %d\n",++tc,tt-Hopcroft());
  }
  return 0;
}