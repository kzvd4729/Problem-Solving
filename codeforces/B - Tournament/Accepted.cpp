/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/02/2019 16:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/27/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50;
int cnt[N+2],mat[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int m=(n*(n-1))/2-1;
  while(m--)
  {
    int u,v;cin>>u>>v;
    cnt[u]++;cnt[v]++;mat[u][v]=1;
  }
  int a=-1,b=-1;
  for(int i=1;i<=n;i++)
  {
    if(cnt[i]<n-1)
    {
      if(a==-1)a=i;
      else b=i;
    }
  }
  for(int i=1;i<=n;i++)
  {
    if(mat[a][i]&&mat[i][b])
      cout<<a<<" "<<b<<endl,exit(0);
  }
  for(int i=1;i<=n;i++)
  {
    if(mat[b][i]&&mat[i][a])
      cout<<b<<" "<<a<<endl,exit(0);
  }
  cout<<a<<" "<<b<<endl;
  return 0;
}