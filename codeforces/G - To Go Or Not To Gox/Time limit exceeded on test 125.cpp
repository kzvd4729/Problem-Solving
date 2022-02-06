/****************************************************************************************
*  @author: kzvd4729                                         created: May/06/2021 00:37                        
*  solution_verdict: Time limit exceeded on test 125         language: GNU C++17 (64)                          
*  run_time: 3000 ms                                         memory_used: 322400 KB                            
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
const long N=2e3,inf=1e18,mod=1e9+7;
 long a[N+2][N+2],w,n,m;
 long d[N+2][N+2];
long dx[]={0,0,1,-1};
long dy[]={1,-1,0,0};
bool isFree(long x,long y)
{
  return ((a[x][y]!=-1) && (x>=1) && (x<=n) && (y>=1) && (y<=m));
}
void bfs(long n,long m,long x,long y)
{
  for(long i=1;i<=n;i++)for(long j=1;j<=m;j++)d[i][j]=inf;
   queue<pair<long,long> >q;
  q.push({x,y});d[x][y]=0;
   while(q.size())
  {
    pair<long,long>p=q.front();q.pop();
     long x=p.first,y=p.second;
    for(long i=0;i<4;i++)
    {
      long xx=x+dx[i],yy=y+dy[i];
      if(d[x][y]+w<d[xx][yy] && isFree(xx,yy))
      {
        d[xx][yy]=d[x][y]+w;
        q.push({xx,yy});
      }
    }
  }
}
 long mn[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>m>>w;
   for(long i=1;i<=n;i++)
  {
    for(long j=1;j<=m;j++)cin>>a[i][j];
  }
   bfs(n,m,1,1);long ans=d[n][m];
    priority_queue<vector<long> >pq;
  for(long i=1;i<=n;i++)
  {
    for(long j=1;j<=m;j++)
    {
      if(a[i][j]>0)pq.push({-a[i][j],i,j});
      mn[i][j]=inf;
    }
  }
     while((long)pq.size())
  {
    vector<long>v=pq.top();pq.pop();
     long c=v[0]*-1,x=v[1],y=v[2];
     if(c>mn[x][y])continue;
    mn[x][y]=c;
    //cout<<x<<" "<<y<<" "<<mn[x][y]<<endl;
     for(long i=0;i<4;i++)
    {
      long xx=x+dx[i],yy=y+dy[i];
      if(mn[x][y]+w<mn[xx][yy] && isFree(xx,yy))
      {
        mn[xx][yy]=mn[x][y]+w;
        pq.push({-(mn[x][y]+w),xx,yy});
      }
    }
  }
  ans=min(ans,mn[1][1]+mn[n][m]);
  if(ans>=inf)ans=-1;
  cout<<ans<<endl;
  return 0;
}