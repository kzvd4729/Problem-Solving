/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/24/2020 14:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 342 ms                                          memory_used: 44400 KB                             
*  problem: https://codeforces.com/contest/229/problem/B
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
const int N=1e6;
const long inf=1e18;
vector<int>bad[N+2];
vector<pair<int,int> >ad[N+2];
long d[N+2],vs[N+2];
void dijkstra(int s,int n)
{
  for(int i=1;i<=n;i++)d[i]=inf,vs[i]=0;d[s]=0;
  priority_queue<pair<int,int> >pq;pq.push({0,s});
    while(pq.size())
  {
    pair<int,int>p=pq.top();pq.pop();
    int nd=p.second;if(vs[nd])continue;
    vs[nd]=1;if(nd==n)return ;
     for( ; ; )
    {
      if(binary_search(bad[nd].begin(),bad[nd].end(),d[nd]))d[nd]++;
      else break;
    }
     for(auto x:ad[nd])
    {
      if(d[nd]+x.second<d[x.first])
      {
        d[x.first]=d[nd]+x.second;
        pq.push({-d[x.first],x.first});
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
    ad[u].push_back({v,w});ad[v].push_back({u,w});
  }
  for(int i=1;i<=n;i++)
  {
    int k;cin>>k;bad[i].resize(k);
    for(int j=0;j<k;j++)cin>>bad[i][j];
  }
  dijkstra(1,n);if(d[n]==inf)d[n]=-1;
  cout<<d[n]<<endl;
    return 0;
}