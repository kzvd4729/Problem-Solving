/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/21/2020 12:40                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 186 ms                                          memory_used: 29200 KB                             
*  problem: https://codeforces.com/contest/590/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3,inf=1e8;
int n,m,dis[N+2][N+2],ds[4][N+2][N+2];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char mt[N+2][N+2];
int bfs(char a,char b)
{
  queue<pair<int,int> >q;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(mt[i][j]==a)
        dis[i][j]=0,q.push({i,j});
      else dis[i][j]=inf;
    }
  }
  while(q.size())
  {
    pair<int,int>p=q.front();q.pop();
    for(int i=0;i<4;i++)
    {
      int x=p.first+dx[i];
      int y=p.second+dy[i];
      if(x>=1&&x<=n&&y>=1&&y<=m&&mt[x][y]=='.')
      {
        if(dis[p.first][p.second]+1<dis[x][y])
        {
          dis[x][y]=dis[p.first][p.second]+1;
          q.push({x,y});
        }
      }
    }
  }
  int mn=inf;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(mt[i][j]!=b)continue;
      for(int k=0;k<4;k++)
      {
        int ii=i+dx[k],jj=j+dy[k];
        if(ii>=1&&ii<=n&&jj>=1&&jj<=m)
          mn=min(mn,dis[ii][jj]);
      }
    }
  }
  return mn;
}
void bfs2(int id,char a)
{
  queue<pair<int,int> >q;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(mt[i][j]==a)
        ds[id][i][j]=0,q.push({i,j});
      else ds[id][i][j]=inf;
    }
  }
  while(q.size())
  {
    pair<int,int>p=q.front();q.pop();
    for(int i=0;i<4;i++)
    {
      int x=p.first+dx[i];
      int y=p.second+dy[i];
      if(x>=1&&x<=n&&y>=1&&y<=m&&mt[x][y]=='.')
      {
        if(ds[id][p.first][p.second]+1<ds[id][x][y])
        {
          ds[id][x][y]=ds[id][p.first][p.second]+1;
          q.push({x,y});
        }
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=m;j++)
      mt[i][j]=s[j-1];
  }
  int ab=bfs('1','2'),ac=bfs('1','3'),bc=bfs('2','3');
  int ans=min(ab+ac,ab+bc);ans=min(ans,ac+bc);
  bfs2(1,'1');bfs2(2,'2');bfs2(3,'3');
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(mt[i][j]=='.')
      {
        ans=min(ans,ds[1][i][j]+ds[2][i][j]+ds[3][i][j]-2);
      }
    }
  }
  if(ans>=inf)ans=-1;
  cout<<ans<<endl;
  return 0;
}