/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/30/2020 17:13                        
*  solution_verdict: Time limit exceeded on test 62          language: GNU C++14                               
*  run_time: 1500 ms                                         memory_used: 4900 KB                              
*  problem: https://codeforces.com/contest/677/problem/D
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
#define long long long
using namespace std;
const int N=3e2,magic=1e3;
int n,m,p,mt[N+2][N+2],ds[N+2][N+2],tmp[N+2][N+2],qd[N+2][N+2];
vector<pair<int,int> >po[N*N+2];
void goNext(int tr)
{
  if(po[tr].size()*po[tr-1].size()<=magic)
  {
    for(auto x:po[tr-1])
    {
      ds[x.first][x.second]=1e9;
      for(auto y:po[tr])
        ds[x.first][x.second]=min(ds[x.first][x.second],ds[y.first][y.second]+abs(x.first-y.first)+abs(x.second-y.second));
    }
    return ;
  }
  queue<pair<int,int> >q;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      tmp[i][j]=1e9;qd[i][j]=0;
      if(mt[i][j]==tr)
      {
        tmp[i][j]=ds[i][j];
        q.push({i,j});qd[i][j]=1;
      }
    }
  }
  auto isV=[](int i,int j)
  {
    if(i<1||i>n||j<1||j>m)return false;
    return true;
  };
  while((int)q.size())
  {
    pair<int,int>p=q.front();q.pop();
    int u=p.first,v=p.second;qd[u][v]=0;
    if(isV(u+1,v)&&tmp[u][v]+1<tmp[u+1][v])
    {
      tmp[u+1][v]=tmp[u][v]+1;
      if(qd[u+1][v]==0)q.push({u+1,v}),qd[u+1][v]=1;
    }
     if(isV(u-1,v)&&tmp[u][v]+1<tmp[u-1][v])
    {
      tmp[u-1][v]=tmp[u][v]+1;
      if(qd[u-1][v]==0)q.push({u-1,v}),qd[u-1][v]=1;
    }
     if(isV(u,v+1)&&tmp[u][v]+1<tmp[u][v+1])
    {
      tmp[u][v+1]=tmp[u][v]+1;
      if(qd[u][v+1]==0)q.push({u,v+1}),qd[u][v+1]=1;
    }
     if(isV(u,v-1)&&tmp[u][v]+1<tmp[u][v-1])
    {
      tmp[u][v-1]=tmp[u][v]+1;
      if(qd[u][v-1]==0)q.push({u,v-1}),qd[u][v-1]=1;
    }
  }
  for(auto x:po[tr-1])ds[x.first][x.second]=tmp[x.first][x.second];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>p;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>mt[i][j];
      po[mt[i][j]].push_back({i,j});
    }
  }
  for(int i=p;i>1;i--)goNext(i);
  int ans=1e9;
  for(auto x:po[1])ans=min(ans,ds[x.first][x.second]+x.first+x.second-2);
  cout<<ans<<endl;
  return 0;
}