/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/26/2020 16:24                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1314/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=80,inf=1e9+1;
int n,k,ds[N+2][N+2][12];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>ds[i][j][1];
      if(i==j)ds[i][j][1]=inf;
    }
  }
  for(int l=2;l<=k;l++)
  {
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)ds[i][j][l]=inf;
  }
  /*for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      cout<<ds[i][j][1]<<" ";
    cout<<endl;
  }*/
  for(int i=2;i<=k;i++)
  {
    for(int a=1;a<=n;a++)
    {
      for(int b=1;b<=n;b++)
      {
        if((a==b)&&(i%2))
        {
          ds[a][b][k]=inf;continue;
        }
        for(int c=1;c<=n;c++)
        {
          ds[a][b][i]=min(ds[a][b][i],ds[a][c][i-1]+ds[c][b][1]);
        }
      }
    }
  }
  cout<<ds[1][1][k]<<endl;
  return 0;
}