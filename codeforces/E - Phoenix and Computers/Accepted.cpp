/****************************************************************************************
*  @author: kzvd4729                                         created: May/06/2021 21:56                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 514 ms                                          memory_used: 8800 KB                              
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
const int N=400,inf=1e9;
int mod;
 int ncr[1000+2][1000+2];
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
int pw[1000+2],dp[N+2][N+2];
int dfs(int ln,int mv)
{
  if(mv<0)return 0;
  if(ln==0)return (mv==0);
   if(dp[ln][mv]!=-1)return dp[ln][mv];
   int ret=0;
  if(ln==mv)ret=pw[ln];
  for(int i=1;i<=ln-2;i++)
  {
    ret=(ret+((1LL*pw[i]*ncr[mv][i])%mod*dfs(ln-i-1,mv-i)))%mod;
  }
  return dp[ln][mv]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n>>mod;
   pw[0]=1;pw[1]=1;
  for(int i=2;i<=1000;i++)
    pw[i]=(pw[i-1]*2)%mod;
   calNCR(1000);
  memset(dp,-1,sizeof dp);
   int ans=0;
  for(int i=1;i<=n;i++)ans=(ans+dfs(n,i))%mod;
   cout<<ans<<endl;
      return 0;
}