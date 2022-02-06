/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/13/2019 20:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1153/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int mt[N+2][N+2],row[N+2],col[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,h;cin>>n>>m>>h;
  for(int i=1;i<=m;i++)cin>>col[i];
  for(int i=1;i<=n;i++)cin>>row[i];
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>mt[i][j];
      if(mt[i][j])mt[i][j]=h;
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(mt[i][j]>row[i])mt[i][j]=row[i];
    }
  }
  for(int j=1;j<=m;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(mt[i][j]>col[j])mt[i][j]=col[j];
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cout<<mt[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}