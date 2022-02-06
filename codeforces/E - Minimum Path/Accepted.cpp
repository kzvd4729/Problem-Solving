/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/14/2021 21:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1184 ms                                         memory_used: 52200 KB                             
*  problem: https://codeforces.com/contest/1473/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
const long inf=1e18;
vector<pair<int,int> >ad[N+2];
long d[N+2][2][2];bool vs[N+2][2][2];
void dijkstra(int s,int n)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<2;j++)
      for(int k=0;k<2;k++)
        d[i][j][k]=inf,vs[i][j][k]=0;
  }
  d[s][0][0]=0;
  priority_queue<vector<long> >pq;pq.push({0,s,0,0});
    while(pq.size())
  {
    vector<long>v=pq.top();pq.pop();
    int nd=v[1],i=v[2],j=v[3];if(vs[nd][i][j])continue;
    vs[nd][i][j]=1;
     if(i==0&&j==0)
    {
      for(auto x:ad[nd])
      {
        if(d[nd][i][j]+x.second<d[x.first][i][j])
        {
          d[x.first][i][j]=d[nd][i][j]+x.second;
          pq.push({-d[x.first][i][j],x.first,i,j});
        }
        if(d[nd][i][j]+x.second*2<d[x.first][i][1])
        {
          d[x.first][i][1]=d[nd][i][j]+x.second*2;
          pq.push({-d[x.first][i][1],x.first,i,1});
        }
        if(d[nd][i][j]<d[x.first][1][j])
        {
          d[x.first][1][j]=d[nd][i][j];
          pq.push({-d[x.first][1][j],x.first,1,j});
        }
        if(d[nd][i][j]+x.second<d[x.first][1][1])
        {
          d[x.first][1][1]=d[nd][i][j]+x.second;
          pq.push({-d[x.first][1][1],x.first,1,1});
        }
      }
    }
    else if(i==0&&j==1)
    {
      for(auto x:ad[nd])
      {
        if(d[nd][i][j]+x.second<d[x.first][i][j])
        {
          d[x.first][i][j]=d[nd][i][j]+x.second;
          pq.push({-d[x.first][i][j],x.first,i,j});
        }
        if(d[nd][i][j]<d[x.first][1][j])
        {
          d[x.first][1][j]=d[nd][i][j];
          pq.push({-d[x.first][1][j],x.first,1,j});
        }
      }
    }
    else if(i==1&&j==0)
    {
      for(auto x:ad[nd])
      {
        if(d[nd][i][j]+x.second<d[x.first][i][j])
        {
          d[x.first][i][j]=d[nd][i][j]+x.second;
          pq.push({-d[x.first][i][j],x.first,i,j});
        }
        if(d[nd][i][j]+x.second*2<d[x.first][i][1])
        {
          d[x.first][i][1]=d[nd][i][j]+x.second*2;
          pq.push({-d[x.first][i][1],x.first,i,1});
        }
      }
    }
    else
    {
      for(auto x:ad[nd])
      {
        if(d[nd][i][j]+x.second<d[x.first][i][j])
        {
          d[x.first][i][j]=d[nd][i][j]+x.second;
          pq.push({-d[x.first][i][j],x.first,i,j});
        }
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    ad[u].push_back({v,w});
    ad[v].push_back({u,w});
  }
  dijkstra(1,n);
  for(int i=2;i<=n;i++)cout<<d[i][1][1]<<" ";cout<<endl;
   return 0;
}