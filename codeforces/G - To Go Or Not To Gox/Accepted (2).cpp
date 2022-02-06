/****************************************************************************************
*  @author: kzvd4729                                         created: May/06/2021 00:57                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 1045 ms                                         memory_used: 98400 KB                             
*  problem: https://codeforces.com/contest/1520/problem/G
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e3,inf=1e9,mod=1e9+7;
 int a[N+2][N+2],n,m,w;
 const long INF=1LL*inf*inf;
long d[N+2][N+2],l[N+2][N+2];
int qd[N+2][N+2];
 int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool isFree(int x,int y)
{
  return ((a[x][y]!=-1) && (x>=1) && (x<=n) && (y>=1) && (y<=m));
}
void bfs(int n,int m,int x,int y)
{
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)d[i][j]=INF;
   queue<pair<int,int> >q;
  q.push({x,y});d[x][y]=0;
   while((int)q.size())
  {
    pair<int,int>p=q.front();q.pop();
     int x=p.first,y=p.second;
    for(int i=0;i<4;i++)
    {
      int xx=x+dx[i],yy=y+dy[i];
      if(d[x][y]+w<d[xx][yy] && isFree(xx,yy))
      {
        d[xx][yy]=d[x][y]+w;
        q.push({xx,yy});
      }
    }
  }
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>m>>w;
   //vector<vector<int> >v;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>a[i][j];
      //if(a[i][j]>0)v.push_back({i,j,a[i][j]});
    }
  }
   bfs(n,m,1,1);
  long ans=d[n][m],mn=INF;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      if(a[i][j]>0)mn=min(mn,d[i][j]+a[i][j]);
  }
   bfs(n,m,n,m);
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      if(a[i][j]>0)ans=min(ans,mn+d[i][j]+a[i][j]);
  }
   if(ans>=INF)ans=-1;cout<<ans<<endl;
     return 0;
}