/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/25/2019 14:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 467 ms                                          memory_used: 126500 KB                            
*  problem: https://codeforces.com/contest/1261/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,m;
string s[N+2];
vector<vector<int> >d,tmp;
vector<pair<int,int> >pos[N+2];
int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={1,-1,0,1,-1,0,1,-1};
bool ok(int c)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      tmp[i][j]=1e9;
  }
  queue<pair<int,int> >q;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      if(d[i][j]>=c)q.push({i,j}),tmp[i][j]=0;
  }
  while(q.size())
  {
    pair<int,int>p=q.front();q.pop();
    int x,y;
    for(int i=0;i<8;i++)
    {
      x=p.first+dx[i],y=p.second+dy[i];
      if(x>=1&&x<=n&&y>=1&&y<=m)
      {
        if(tmp[p.first][p.second]+1<tmp[x][y])
          tmp[x][y]=tmp[p.first][p.second]+1,q.push({x,y});
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      if(d[i][j]<c&&d[i][j]>0&&tmp[i][j]>=c)return 0;
  }
  return 1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
   d.resize(n+2),tmp.resize(n+2);
  for(int i=0;i<n+2;i++)d[i].resize(m+2),tmp[i].resize(m+2);
    for(int i=0;i<n;i++)cin>>s[i];
   for(int i=0;i<=n+1;i++)for(int j=0;j<=m+1;j++)d[i][j]=1e9;
   queue<pair<int,int> >q;
  for(int i=0;i<=n+1;i++)
  {
    q.push({i,0});q.push({i,m+1});
    d[i][0]=0;d[i][m+1]=0;
  }
  for(int j=0;j<=m+1;j++)
  {
    q.push({0,j});q.push({n+1,j});
    d[0][j]=0;d[n+1][j]=0; 
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(s[i-1][j-1]=='.')
        q.push({i,j}),d[i][j]=0;
    }
  }
  while(q.size())
  {
    pair<int,int>p=q.front();q.pop();
    int x,y;
    for(int i=0;i<8;i++)
    {
      x=p.first+dx[i],y=p.second+dy[i];
      if(x>=1&&x<=n&&y>=1&&y<=m)
      {
        if(d[p.first][p.second]+1<d[x][y])
          d[x][y]=d[p.first][p.second]+1,q.push({x,y});
      }
    }
  }
  int lo=1,hi=0,md;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      hi=max(hi,d[i][j]);
  }
  hi++;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ok(md))lo=md;else hi=md;
  }
  for(md=lo;md<=hi;md++)
    if(!ok(md))break;
  md--;
  cout<<md-1<<"\n";
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(d[i][j]>=md)cout<<'X';
      else cout<<'.';
    }
    cout<<"\n";
  }
  return 0;
}