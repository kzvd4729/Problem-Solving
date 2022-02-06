/****************************************************************************************
*  @author: kzvd4729                                         created: May/02/2021 23:34                        
*  solution_verdict: Time limit exceeded on pretest 3        language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 6500 KB                              
*  problem: https://codeforces.com/contest/1515/problem/E
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=400,inf=1e9,mod=1e9+7;
 #pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
 int ncr[1000+2][1000+2],dp[N+2][N+2][2][2];
void calNCR(int n)
{
  for(int i=1;i<=n;i++)ncr[i][0]=1;
  ncr[1][1]=1;
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;////use mod
  }
  ncr[0][0]=1;
}
void dfs(int tt)
{
  dp[0][0][0][0]=1;
  dp[0][0][0][1]=1;
  dp[0][0][1][0]=1;
  dp[0][0][1][1]=1;
   dp[1][0][1][1]=1;
  dp[1][1][0][0]=1;
  dp[1][1][0][1]=1;
  dp[1][1][1][0]=1;
   for(int l=2;l<=tt;l++)
  {
    for(int mv=l/2-1;mv<=l;mv++)
    {
      for(int f1=0;f1<=1;f1++)
      {
        for(int f2=0;f2<=1;f2++)
        {
          long ret=0;
          for(int i=1;i<=l;i++)
          {
            for(int m=max(0,i/2-1);m<i;m++)
            {
              long ml=1;
              ml=(ml*dp[i-1][m][f1][1]);
              ml=(ml*dp[l-i][mv-m-1][1][f2])%mod;
              ml=(ml*ncr[mv-1][m])%mod;
                            ret=ret+ml;
            }
          }
          dp[l][mv][f1][f2]=ret%mod;
        }
      }
    }
  }
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   calNCR(1000);
   int ans=0;
   int n;cin>>n;dfs(n);
  for(int i=0;i<=n;i++)
  {
    ans=(ans+dp[n][i][0][0])%mod;
    //cout<<i<<" "<<dfs(n,i,0,0)<<endl;
  }
   cout<<ans<<endl;
    return 0;
}