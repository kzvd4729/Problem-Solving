/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/18/2018 04:50                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 17600 KB                             
*  problem: https://codeforces.com/contest/333/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const int b1=991,b2=997;
int n,m,mat[N+2][N+2],clr[1000006],id;
vector<int>v[N+2];
bool vis[10000007];
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
  if(cnt>30*n)return true;
  for(int i=1;i<=id;i++)vis[clr[id]]=0;
  id=0;
  for(int i=1;i<=n;i++)
  {
    int l=v[i].size();
    for(int j=0;j<l;j++)
    {
      for(int k=j+1;k<l;k++)
      {
        int hs=v[i][j]*b1+v[i][k]*b2;
        if(vis[hs])return true;
        vis[hs]=1;clr[++id]=hs;
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