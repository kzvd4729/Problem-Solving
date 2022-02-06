/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/28/2019 17:56                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 5500 KB                              
*  problem: https://codeforces.com/contest/762/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[4][N+2];long dp[4][N+2],qm[N+2];
long max(long a,long b,long c)
{
  return max(a,max(b,c));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=3;i++)
    for(int j=1;j<=n;j++)
      cin>>aa[i][j],qm[j]+=aa[i][j];
  for(int i=1;i<=n;i++)qm[i]+=qm[i-1];
//  for(int i=1;i<=n;i++)
//    cout<<qm[i]<<" ";
//  cout<<endl;
  dp[1][1]=aa[1][1];
  dp[2][1]=aa[2][1]+aa[1][1];
  dp[3][1]=aa[3][1]+aa[2][1]+aa[1][1];
   long mx1=dp[1][1]-qm[1],mx2=dp[3][1]-qm[1];
  for(int i=2;i<=n;i++)
  {
    dp[1][i]=max(dp[1][i-1],dp[2][i-1]+aa[2][i],dp[3][i-1]+aa[3][i]+aa[2][i])+aa[1][i];
    dp[2][i]=max(dp[1][i-1]+aa[1][i],dp[2][i-1],dp[3][i-1]+aa[3][i])+aa[2][i];
    dp[3][i]=max(dp[1][i-1]+aa[1][i]+aa[2][i],dp[2][i-1]+aa[2][i],dp[3][i-1])+aa[3][i];
     //cout<<mx1<<" == "<<mx2<<endl;
    dp[1][i]=max(dp[1][i],mx2+qm[i]);
    dp[3][i]=max(dp[3][i],mx1+qm[i]);
      mx1=max(mx1,dp[1][i]-qm[i]),mx2=max(mx2,dp[3][i]-qm[i]);
  }
//  cout<<endl;
//  for(int j=1;j<=3;j++)
//  {
//    for(int i=1;i<=n;i++)
//      cout<<dp[j][i]<<" ";
//    cout<<endl;
//  }
  cout<<dp[3][n]<<endl;
  return 0;
}