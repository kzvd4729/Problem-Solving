/****************************************************************************************
*  @author: kzvd4729                                         created: May/08/2019 21:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 600 KB                               
*  problem: https://codeforces.com/contest/601/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e2;
int mt[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      mt[i][j]=1e9;
  while(m--)
  {
    int u,v;cin>>u>>v;
    mt[u][v]=1;mt[v][u]=1;
  }
  if(mt[1][n]==1)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=i+1;j<=n;j++)
      {
        if(mt[i][j]==1)
        {
          mt[i][j]=1e9;
          mt[j][i]=1e9;
        }
        else
        {
          mt[i][j]=1;
          mt[j][i]=1;
        }
      }
    }
  }
  for(int k=1;k<=n;k++)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        mt[i][j]=min(mt[i][j],mt[i][k]+mt[k][j]);
      }
    }
  }
  if(mt[1][n]==1e9)mt[1][n]=-1;
  cout<<mt[1][n]<<endl;
  return 0;
}