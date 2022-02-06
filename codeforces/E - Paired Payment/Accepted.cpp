/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/18/2021 22:43                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 623 ms                                          memory_used: 450800 KB                            
*  problem: https://codeforces.com/contest/1486/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=2e9+9,mod=1e9+7;
 vector<pair<int,int> >ad[N+2];
int d[N+2][50+2],vs[N+2][50+2];
void dijkstra(int n)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=50;j++)d[i][j]=inf;
  }
  priority_queue<vector<int> >pq;pq.push({0,1,0});
  d[1][0]=0;//vs[1][0]=1;
   while(pq.size())
  {
    vector<int>v=pq.top();pq.pop();
    int i=v[1],j=v[2];if(vs[i][j])continue;
    v[0]*=-1;
    vs[i][j]=1;
     for(auto x:ad[i])
    {
      if(j==0)
      {
        if(v[0]<d[x.first][x.second])
        {
          d[x.first][x.second]=v[0];
          pq.push({-v[0],x.first,x.second});
        }
      }
      else
      {
        if(v[0]+(j+x.second)*(j+x.second)<d[x.first][0])
        {
          d[x.first][0]=v[0]+(j+x.second)*(j+x.second);
          pq.push({-d[x.first][0],x.first,0});
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
   dijkstra(n);
  for(int i=1;i<=n;i++)
  {
    if(d[i][0]==inf)d[i][0]=-1;
    cout<<d[i][0]<<" ";
  }
  cout<<endl;
   return 0;
}