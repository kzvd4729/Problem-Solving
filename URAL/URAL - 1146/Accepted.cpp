/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-10 22:26:30                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 62                                         memory_used (MB): 0.5                             
*  problem: https://vjudge.net/problem/URAL-1146
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int mat[102][102],n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin>>mat[i][j];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      mat[i][j]+=mat[i][j-1];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      mat[i][j]+=mat[i-1][j];
  int ans=-1e8;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      for(int k=i;k<=n;k++)
        for(int l=j;l<=n;l++)
          ans=max(ans,mat[k][l]-mat[k][j-1]-mat[i-1][l]+mat[i-1][j-1]);
  cout<<ans<<endl;
  return 0;
}