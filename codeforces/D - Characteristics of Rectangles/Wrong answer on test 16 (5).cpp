/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/18/2018 04:06                        
*  solution_verdict: Wrong answer on test 16                 language: GNU C++14                               
*  run_time: 686 ms                                          memory_used: 20200 KB                             
*  problem: https://codeforces.com/contest/333/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int n,m,mat[N+2][N+2],vis[N+2][N+2];
bool ok(int x)
{
  vector<pair<int,int> >v;int cnt=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(mat[i][j]>=x)
      {
        cnt++;vis[i][j]=1;
        v.push_back({i,j});
      }
      else vis[i][j]=0;
    }
  }
  if(cnt>=25*N)return true;
  for(int i=0;i<v.size();i++)
  {
    for(int j=i+1;j<v.size();j++)
    {
      if(abs(v[i].first-v[j].first)>=1&&abs(v[i].second-v[j].second)>=1)
      {
        if(vis[v[i].first][v[j].second]&&vis[v[j].first][v[i].second])return true;
      }
    }
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>mat[i][j];
    }
  }
  int lo=0,hi=1e9+9,md;
  while(hi-lo>3)
  {
    md=(hi+lo)/2;
    if(ok(md))lo=md;
    else hi=md;
  }
  for(md=hi;md>=lo;md--)
    if(ok(md))cout<<md<<endl,exit(0);
  return 0;
}