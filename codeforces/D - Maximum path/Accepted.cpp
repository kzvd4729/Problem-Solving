/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/28/2019 19:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 7100 KB                              
*  problem: https://codeforces.com/contest/762/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
long aa[4][N+2],dp[4][N+2],qm[N+2];
long max(long a,long b,long c){return max(a,max(b,c));}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=3;i++)
    for(int j=1;j<=n;j++)
      cin>>aa[i][j],qm[j]+=aa[i][j];
  for(int i=1;i<=n;i++)qm[i]+=qm[i-1];
   dp[1][1]=aa[1][1];
  dp[2][1]=aa[2][1]+aa[1][1];
  dp[3][1]=aa[3][1]+aa[2][1]+aa[1][1];
   long mx1=max(dp[1][1]-qm[1],0LL),mx2=max(dp[3][1]-qm[1],0LL);
  long mx3=0,mx4=0;
  for(int i=2;i<=n;i++)
  {
    dp[1][i]=max(dp[1][i-1],dp[2][i-1]+aa[2][i],dp[3][i-1]+aa[3][i]+aa[2][i])+aa[1][i];
     dp[2][i]=max(dp[1][i-1]+aa[1][i],dp[2][i-1],dp[3][i-1]+aa[3][i])+aa[2][i];
     dp[3][i]=max(dp[1][i-1]+aa[1][i]+aa[2][i],dp[2][i-1]+aa[2][i],dp[3][i-1])+aa[3][i];
     dp[1][i]=max(dp[1][i],max(mx2,mx4)+qm[i]);
    dp[3][i]=max(dp[3][i],max(mx1,mx3)+qm[i]);
     if(i%2==0)
    {
      dp[1][i]=max(dp[1][i],mx3+qm[i]);
      dp[3][i]=max(dp[3][i],mx4+qm[i]);
      mx3=max(mx3,dp[1][i]-qm[i]),mx4=max(mx4,dp[3][i]-qm[i]);
    }
    else
    {
      dp[1][i]=max(dp[1][i],mx1+qm[i]);
      dp[3][i]=max(dp[3][i],mx2+qm[i]);
      mx1=max(mx1,dp[1][i]-qm[i]),mx2=max(mx2,dp[3][i]-qm[i]);
    }
  }
  cout<<dp[3][n]<<endl;
  return 0;
}