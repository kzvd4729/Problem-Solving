/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-04-12 18:28:24                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 248 ms                                          memory_used: 164576 KB                            
*  problem: https://atcoder.jp/contests/abc162/tasks/abc162_f
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long aa[N+2];
map<int,long>dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];
    //aa[i]=rand();
  }
   dp[0][0]=0;dp[1][0]=0;dp[1][1]=aa[1];
  for(int i=2;i<=n;i++)
  {
    for(int j=i/2-4;j<=i/2+4;j++)
    {
      if(j<0)continue;if(j==0)dp[i][j]=0;
      dp[i][j]=-1e18;
      if(dp[i-1].count(j))dp[i][j]=dp[i-1][j];
      if(dp[i-2].count(j-1))dp[i][j]=max(dp[i][j],aa[i]+dp[i-2][j-1]);
    }
  }
  cout<<dp[n][n/2]<<endl;
  return 0;
}