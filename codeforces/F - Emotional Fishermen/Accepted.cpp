/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/31/2020 23:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 98000 KB                             
*  problem: https://codeforces.com/contest/1437/problem/F
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
const int N=5e3;
const int mod=998244353;
int ncr[N+2][N+2],fac[N+2];
void calNCR(int n)
{
  for(int i=1;i<=n;i++)ncr[i][0]=1;
  ncr[1][1]=1;
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
  }
  ncr[0][0]=1;fac[0]=1;
  for(int i=1;i<=n;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
}
int a[N+2],bad[N+2],n,dp[N+2];
int dfs(int l)
{
  if(l==n)return (bad[l]==0);
  if(dp[l]!=-1)return dp[l];
  int ret=0;
  for(int i=l+1;i<=n;i++)
  {
    if(a[i]>=a[l]+a[l])
    {
      int pl=l-bad[l],nw=i-bad[i];
      ret=(ret+(1LL*ncr[n-pl-1][nw-pl-1]*fac[nw-pl-1])%mod*dfs(i))%mod;
    }
  }
  return dp[l]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  calNCR(N);cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
  {
    for(int j=i-1;j>=1;j--)
      if(2*a[j]>a[i])bad[i]++;
  }
  memset(dp,-1,sizeof dp);
  cout<<dfs(0)<<endl;
    return 0;
}