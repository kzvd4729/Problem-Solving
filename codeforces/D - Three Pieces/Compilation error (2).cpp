/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/11/2018 21:47                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1065/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
const long N=10,R=100;
int n,mat[N+2][N+2],dis[N+2][N+2],all[N+2][4];
vector<pair<int,int> >pos[R+2];
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
  dis[sr][sc]=0;
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>mat[i][j];
      pos[mat[i][j]].push_back({i,j});
    }
  }
  for(int i=1;i<n*n;i++)
  {
    all[i][0]=bfs_knight(pos[i].first,pos[i].second,pos[i+1].first,pos[i+1].second);
    all[i][1]=bfs_rook(pos[i].first,pos[i].second,pos[i+1].first,pos[i+1].second);
    all[i][2]=bfs_bishop(pos[i].first,pos[i].second,pos[i+1].first,pos[i+1].second);
  }
  return 0;
}