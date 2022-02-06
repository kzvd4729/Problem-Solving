/****************************************************************************************
*  @author: kzvd4729#                                        created: May/29/2020 16:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 207600 KB                            
*  problem: https://codeforces.com/contest/467/problem/C
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];long qm[N+2];
long dp[5000+2][5000+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=n;i++)cin>>aa[i],qm[i]=qm[i-1]+aa[i];
   for(int i=1;i<=k;i++)
  {
    for(int j=1;j<=n;j++)
    {
      dp[i][j]=dp[i][j-1];
      if(j>=m)dp[i][j]=max(dp[i][j],dp[i-1][j-m]+qm[j]-qm[j-m]);
    }
  }
  cout<<dp[k][n]<<endl;
    return 0;
}