/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/18/2018 05:01                        
*  solution_verdict: Wrong answer on test 46                 language: GNU C++14                               
*  run_time: 872 ms                                          memory_used: 60900 KB                             
*  problem: https://codeforces.com/contest/333/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const int b1=991,b2=1117;
int n,m,mat[N+2][N+2];
vector<int>v[N+2],clr;
bool vis[50000007];
bool ok(int x)
{
  int cnt=0;
  for(int i=1;i<=n;i++)
  {
    v[i].clear();
    for(int j=1;j<=m;j++)
    {
      if(mat[i][j]>=x)
      {
        v[i].push_back(j);
        cnt++;
      }
    }
  }
  if(cnt>100*n)return true;
  for(auto x:clr)vis[x]=0;
  clr.clear();
  for(int i=1;i<=n;i++)
  {
    int l=v[i].size();
    for(int j=0;j<l;j++)
    {
      for(int k=j+1;k<l;k++)
      {
        int hs=v[i][j]*b1+v[i][k]*b2;
        if(vis[hs])return true;
        vis[hs]=1;clr.push_back(hs);
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
  while(hi-lo>1)
  {
    md=(hi+lo)/2;
    if(ok(md))lo=md;
    else hi=md;
  }
  for(md=hi;md>=lo;md--)
    if(ok(md))cout<<md<<endl,exit(0);
  return 0;
}