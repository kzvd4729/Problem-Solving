/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-12 18:17:30                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 8 ms                                            memory_used: 8064 KB                              
*  problem: https://atcoder.jp/contests/abc151/tasks/abc151_d
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int n,m,ds[20+2][20+2],ans;
string s[N+2];
void bfs(int sr,int sc)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)ds[i][j]=inf;
  }
  queue<pair<int,int> >q;q.push({sr,sc});
  ds[sr][sc]=0;
   while(q.size())
  {
    pair<int,int>p=q.front();q.pop();
     int u=p.first,v=p.second+1;
    if(u>=0&&v>=0&&u<n&&v<m&&s[u][v]=='.'&&ds[p.first][p.second]+1<ds[u][v])
    {
      ds[u][v]=ds[p.first][p.second]+1;q.push({u,v}); 
    }
     u=p.first,v=p.second-1;
    if(u>=0&&v>=0&&u<n&&v<m&&s[u][v]=='.'&&ds[p.first][p.second]+1<ds[u][v])
    {
      ds[u][v]=ds[p.first][p.second]+1;q.push({u,v}); 
    }
     u=p.first+1,v=p.second;
    if(u>=0&&v>=0&&u<n&&v<m&&s[u][v]=='.'&&ds[p.first][p.second]+1<ds[u][v])
    {
      ds[u][v]=ds[p.first][p.second]+1;q.push({u,v}); 
    }
     u=p.first-1,v=p.second;
    if(u>=0&&v>=0&&u<n&&v<m&&s[u][v]=='.'&&ds[p.first][p.second]+1<ds[u][v])
    {
      ds[u][v]=ds[p.first][p.second]+1;q.push({u,v}); 
    }
  }
   for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
      if(ds[i][j]<inf)ans=max(ans,ds[i][j]);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>s[i];
   for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(s[i][j]=='.')
        bfs(i,j);
    }
  }
  cout<<ans<<endl;
  return 0;
}