/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/16/2018 16:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 404 ms                                          memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/25/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e2;
int n,m,a,b,w,mat[N+2][N+2];
long ans;
void sum(void)
{
  ans=0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
      ans+=(mat[i][j]*1LL);
//  for(int i=1;i<=n;i++)
//  {
//    for(int j=1;j<=n;j++)
//    {
//      cout<<mat[i][j]<<" ";
//    }
//    cout<<endl;
//  }
  cout<<ans<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin>>mat[i][j];
   for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
  cin>>m;
  while(m--)
  {
    cin>>a>>b>>w;
    if(mat[a][b]<=w)sum();
    else
    {
      mat[a][b]=w;
      mat[b][a]=w;
      for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
          mat[i][j]=min(mat[i][j],mat[j][i]);
          mat[i][j]=min(mat[i][j],mat[i][a]+mat[a][b]+mat[b][j]);
          mat[i][j]=min(mat[i][j],mat[i][b]+mat[b][a]+mat[a][j]);
        }
      sum();
    }
  }
   return 0;
}