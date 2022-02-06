/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/10/2018 17:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 343 ms                                          memory_used: 17100 KB                             
*  problem: https://codeforces.com/contest/837/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2;
const int MX=N*27;
int n,k,dp[4][N+2][MX+2];
long x;
pair<int,int>arr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    int two=0,five=0;
    while(x%2==0)
    {
      x/=2;
      two++;
    }
    while(x%5==0)
    {
      x/=5;
      five++;
    }
    arr[i]={two,five};
    //cout<<two<<" "<<five<<endl;
  }
  for(int i=0;i<2;i++)
    for(int j=0;j<=k;j++)
      for(int ii=0;ii<=MX;ii++)
        dp[i][j][ii]=-1e9;
  dp[0][0][0]=0;
  dp[1][0][0]=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=k;j++)
    {
      for(int ii=0;ii<=MX;ii++)
      {
        dp[i%2][j][ii]=dp[(i+1)%2][j][ii];
        if(ii-arr[i].second>=0)dp[i%2][j][ii]=max(dp[i%2][j][ii],dp[(i+1)%2][j-1][ii-arr[i].second]+arr[i].first);
//        if(dp[i][j][ii]>0)
//          cout<<i<<" "<<j<<" "<<ii<<" "<<dp[i][j][ii]<<endl;
      }
    }
  }
  int ans=0;
  for(int i=1;i<=MX;i++)
    ans=max(ans,min(i,dp[n%2][k][i]));
  cout<<ans<<endl;
  return 0;
}