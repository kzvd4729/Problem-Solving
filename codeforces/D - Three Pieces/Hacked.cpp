/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/11/2018 22:12                        
*  solution_verdict: Hacked                                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1065/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
const int R=100;
pair<int,int>dp[R+2][R+2];
int n,mat[R+2][R+2],dis[R+2][R+2],all[R+2][R+2];
int vis[R+2][R+2];
pair<int,int>pos[R+2];
int dx[]={-2,-1,1,2,-2,-1,1,2};
int dy[]={-1,-2,-2,-1,1,2,2,1};
bool valid(int x,int y)
{
  if(x<1||y<1||x>n||y>n)return false;
  return true;
}
int bfs_knight(int sr,int sc,int tr,int tc)
{
  queue<pair<int,int> >q;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      dis[i][j]=inf;
  dis[sr][sc]=0;q.push({sr,sc});
  while(q.size())
  {
    pair<int,int>p=q.front();q.pop();
    for(int i=0;i<8;i++)
    {
      int a=p.first+dx[i];
      int b=p.second+dy[i];
      if(valid(a,b))
      {
        if(dis[a][b]==inf)
        {
          dis[a][b]=dis[p.first][p.second]+1;
          q.push({a,b});
        }
      }
    }
  }
  return dis[tr][tc];
}
int bfs_rook(int sr,int sc,int tr,int tc)
{
  if(sr==tr||sc==tc)return 1;
  else return 2;
}
int bfs_bishop(int sr,int sc,int tr,int tc)
{
  if((sr+sc)%2!=(tr+tc)%2)return inf;
  if(abs(sr-tr)==abs(sc-tc))return 1;
  else return 2;
}
pair<int,int>dfs(int st,int cur)
{
  if(st==n*n)return {0,0};
  if(vis[st][cur])return dp[st][cur];
  vis[st][cur]=1;
  pair<int,int>here={inf,inf};
  for(int i=0;i<3;i++)
  {
    int ex;
    if(i==cur)ex=0;
    else ex=1;
    pair<int,int>ret=dfs(st+1,i);
    ret.first+=ex+all[st][i];
    ret.second+=ex;
     here=min(here,ret);
  }
  return dp[st][cur]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>mat[i][j];
      pos[mat[i][j]]={i,j};
    }
  }
  for(int i=1;i<n*n;i++)
  {
    all[i][0]=bfs_knight(pos[i].first,pos[i].second,pos[i+1].first,pos[i+1].second);
    all[i][1]=bfs_rook(pos[i].first,pos[i].second,pos[i+1].first,pos[i+1].second);
    all[i][2]=bfs_bishop(pos[i].first,pos[i].second,pos[i+1].first,pos[i+1].second);
  }
//  for(int i=1;i<n*n;i++)
//  {
//    cout<<all[i][0]<<" "<<all[i][1]<<" "<<all[i][2]<<endl;
//  }
  for(int i=0;i<=R;i++)
  {
    for(int j=0;j<10;j++)
    {
      dp[i][j]={inf,inf};
    }
  }
  memset(vis,0,sizeof(vis));
  pair<int,int>ans=dfs(1,0);
   for(int i=0;i<=R;i++)
  {
    for(int j=0;j<10;j++)
    {
      dp[i][j]={inf,inf};
    }
  }
  memset(vis,0,sizeof(vis));
  ans=min(ans,dfs(1,1));
   for(int i=0;i<=R;i++)
  {
    for(int j=0;j<10;j++)
    {
      dp[i][j]={inf,inf};
    }
  }
  memset(vis,0,sizeof(vis));
  ans=min(ans,dfs(1,2));
   cout<<ans.first<<" "<<ans.second<<endl;
   return 0;
}