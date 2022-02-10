/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-22 01:02:59                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-KATHTHI
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const int inf=9;
int dis[N+2][N+2];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char mt[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      string s;cin>>s;
      for(int j=1;j<=m;j++)
        mt[i][j]=s[j-1],dis[i][j]=inf;
    }
    queue<pair<int,int> >q;q.push({1,1});
    dis[1][1]=0;queue<pair<int,int> >tmp;
    while(true)
    {
      while(q.size())
      {
        pair<int,int>p=q.front();q.pop();
        for(int i=0;i<4;i++)
        {
          int x=p.first+dx[i];
          int y=p.second+dy[i];
          if(x>=1&&x<=n&&y>=1&&y<=m)
          {
            if(mt[x][y]==mt[p.first][p.second])
            {
              if(dis[p.first][p.second]<dis[x][y])
              {
                dis[x][y]=dis[p.first][p.second];
                q.push({x,y});
              }
            }
            else
            {
              if(dis[p.first][p.second]+1<dis[x][y])
              {
                dis[x][y]=dis[p.first][p.second]+1;
                tmp.push({x,y});
              }
            }
          }
        }
      }
      if(tmp.size()==0)break;
      q=tmp;while(tmp.size())tmp.pop();
    }
    cout<<dis[n][m]<<endl;
  }
  return 0;
}