/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/01/2020 15:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1433/problem/G
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
const int N=1e3,inf=1e9;
vector<pair<int,int> >adj[N+2];
int d[N+2],qd[N+2];
void spfa(int sr,int n)
{
  for(int i=1;i<=n;i++)d[i]=inf,qd[i]=0;
  queue<int>q;q.push(sr);qd[sr]=1,d[sr]=0;
  while(q.size())
  {
    int u=q.front();q.pop();qd[u]=0;
    for(auto x:adj[u])
    {
      if(d[u]+x.second<d[x.first])
      {
        d[x.first]=d[u]+x.second;
        if(!qd[x.first])q.push(x.first),qd[x.first]=1;
      }
    }
  }
}
int ds[N+2][N+2],a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  vector<vector<int> >ed;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;ed.push_back({u,v,w});
    adj[u].push_back({v,w});adj[v].push_back({u,w});
  }
  for(int i=1;i<=n;i++)
  {
    spfa(i,n);
    for(int j=1;j<=n;j++)ds[i][j]=d[j];
  }
  for(int i=1;i<=k;i++)cin>>a[i]>>b[i];
   int ans=inf;
  for(auto x:ed)
  {
    int now=0;
    for(int i=1;i<=k;i++)
    {
      int u=a[i],v=b[i];
      now+=min(ds[u][v],min(ds[x[0]][u]+ds[x[1]][v],ds[x[0]][v]+ds[x[1]][u]));
    }
    ans=min(ans,now);
  }
  cout<<ans<<endl;
  return 0;
}