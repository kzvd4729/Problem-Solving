/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/06/2020 13:54                        
*  solution_verdict: Wrong answer on test 16                 language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 236400 KB                            
*  problem: https://codeforces.com/contest/1140/problem/E
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
#include<stack>
#include<deque>
#define long long long
using namespace std;
const long N=2e5,mod=998244353;
long k,dp1[N+2][2],sz,dp2[N+2][2][2],dp[200000+2][10+2][10+2],aa[N+2],n;
long dfs(long i,long a,long b)
{
  if(i>n)return 1;
  if(dp[i][a][b]!=-1)return dp[i][a][b];
  if(aa[i]!=-1)
  {
    if(aa[i]==a)return 0;
    return dp[i][a][b]=dfs(i+1,b,aa[i]);
  }
  else
  {
    long ret=0;
    for(int j=1;j<=k;j++)
    {
      if(j==a)continue;
      ret=(ret+dfs(i+1,b,j))%mod;
    }
    return dp[i][a][b]=ret;
  }
}
long dfs1(long i,long l)
{
  if(i>sz)return !l;
  if(dp1[i][l]!=-1)return dp1[i][l];
  long ret=0;
  if(l)ret=(ret+1LL*(k-1)*dfs1(i+1,0))%mod;
  else
  {
    ret=(ret+1LL*(k-2)*dfs1(i+1,0))%mod;
    ret=(ret+dfs1(i+1,1))%mod;
  }
  return dp1[i][l]=ret;
}
long dfs2(long i,long l,long r)
{
  if(i>sz)return !r;
  if(dp2[i][l][r]!=-1)return dp2[i][l][r];
  long ret=0;
  if(l)
  {
    ret=(ret+1LL*(k-2)*dfs2(i+1,0,0))%mod;
    ret=(ret+dfs2(i+1,0,1))%mod;
  }
  if(r)
  {
    ret=(ret+1LL*(k-2)*dfs2(i+1,0,0))%mod;
    ret=(ret+dfs2(i+1,1,0))%mod;
  }
  return dp2[i][l][r]=ret;
}
long solve(long a,long b,long n)
{  
  if(n==0)return 1;sz=n;
  if(a==-1&&b==-1)
  {
    long ret=k;
    for(long i=2;i<=n;i++)ret=(ret*(k-1))%mod;
    return ret;
  }
  if(a==-1||b==-1)
  {
    long ret=1;
    for(long i=1;i<=n;i++)ret=(ret*(k-1))%mod;
    return ret;
  }
  if(a==b)
  {
    for(long i=1;i<=n;i++)dp1[i][0]=-1,dp1[i][1]=-1;
    return dfs1(1,1);
  }
  for(long i=1;i<=n;i++)dp2[i][0][0]=-1,dp2[i][0][1]=-1,dp2[i][1][0]=-1,dp2[i][1][1]=-1;
  return dfs2(1,1,0);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(long i=1;i<=n;i++)cin>>aa[i];
  for(long i=2;i<n;i++)
  {
    if(aa[i-1]>0&&aa[i+1]>0&&aa[i-1]==aa[i+1])cout<<0<<endl,exit(0);
  }
  memset(dp,-1,sizeof dp);
  //if(k<=10)cout<<dfs(1,0,0)<<endl,exit(0);
  long l=-1,cnt=0;long ans=1;
  for(long i=1;i<=n;i+=2)
  {
    if(aa[i]==-1)cnt++;
    else
    {
      ans*=solve(l,aa[i],cnt);
      cnt=0;l=aa[i];ans%=mod;
    }
  }
  ans*=solve(l,-1,cnt);ans%=mod;
   l=-1,cnt=0;
  for(long i=2;i<=n;i+=2)
  {
    if(aa[i]==-1)cnt++;
    else
    {
      ans*=solve(l,aa[i],cnt);
      cnt=0;l=aa[i];ans%=mod;
    }
  }
  ans*=solve(l,-1,cnt);ans%=mod;
   cout<<ans<<endl;
   return 0;
}