/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/10/2020 16:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 1200 KB                              
*  problem: https://codeforces.com/contest/1312/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=500;
int aa[N+2],dp[N+2][N+2],ls[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   memset(dp,-1,sizeof(dp));
  for(int i=1;i<=n;i++)dp[i][i]=aa[i];
   for(int l=2;l<=n;l++)
  {
    for(int i=1;i<=n-l+1;i++)
    {
      int j=i+l-1;
      for(int k=i;k<j;k++)
      {
        if(dp[i][k]==dp[k+1][j]&&dp[i][k]!=-1)
          dp[i][j]=dp[i][k]+1;
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(dp[i][j]==-1)dp[i][j]=n;
      else dp[i][j]=1;
    }
  }
  for(int i=1;i<=n;i++)
  {
    ls[i]=n;
    for(int j=1;j<=i;j++)
      ls[i]=min(ls[i],dp[j][i]+ls[j-1]);
  }
  cout<<ls[n]<<endl;
  return 0;
}