/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-15 23:37:16                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 640                                        memory_used (MB): 15.4                            
*  problem: https://vjudge.net/problem/SPOJ-BITMAP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
int t,n,m,mat[202][202],dis[202][202];
string s;
vector<pair<int,int> >v;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void bfs(int r,int c)
{
  queue<pair<int,int> >q;
  pair<int,int>x;
  dis[r][c]=0;
  q.push({r,c});
  while(q.size())
  {
    x=q.front();
    q.pop();
    int rw=x.first;
    int cl=x.second;
    for(int i=0;i<4;i++)
    {
      int xx=rw+dx[i];
      int yy=cl+dy[i];
      if(xx<1||xx>n||yy<1||yy>m)continue;
      if(dis[rw][cl]+1<dis[xx][yy])
      {
        q.push({xx,yy});
        dis[xx][yy]=dis[rw][cl]+1;
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    v.clear();
    for(int i=1;i<=n;i++)
    {
      cin>>s;
      for(int j=1;j<=m;j++)
      {
        mat[i][j]=s[j-1];
        if(mat[i][j]=='1')v.push_back({i,j});
      }
    }
    for(int i=0;i<=200;i++)
    {
      for(int j=0;j<=200;j++)dis[i][j]=inf;
    }
    for(auto x:v)bfs(x.first,x.second);

    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        cout<<dis[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}