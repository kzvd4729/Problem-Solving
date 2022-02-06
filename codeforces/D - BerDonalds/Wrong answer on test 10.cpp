/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/08/2020 13:41                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 1746 ms                                         memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/266/problem/D
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
const int N=200,inf=1e9;
int d[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=inf;
  for(int i=1;i<=n;i++)d[i][i]=0;
   vector<vector<int> >ed;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    d[u][v]=min(d[u][v],w);d[v][u]=min(d[v][u],w);
    ed.push_back({u,v,w});
  }
  for(int k=1;k<=n;k++)
  {
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
  }
  double ans=inf;
  for(auto x:ed)
  {
    int u=x[0],v=x[1],w=x[2];
    double lo=0,hi=w,md1,md2,mx1,mx2;int lp=100;
    while(lp--)
    {
      md1=(lo+lo+hi)/3.0,md2=(lo+hi+hi)/3.0;
      mx1=0,mx2=0;
      for(int i=1;i<=n;i++)
      {
        mx1=max(mx1,min(md1+d[u][i],w-md1+d[v][i]));
        mx2=max(mx2,min(md2+d[u][i],w-md2+d[v][i]));
      }
      if(mx1<mx2)hi=md2;else lo=md1;
    }
    ans=min(ans,mx1);
  }
  cout<<setprecision(10)<<fixed<<ans<<endl;
  return 0;
}