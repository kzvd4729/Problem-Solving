/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/03/2018 16:54                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/544/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2;
int n,m,b,arr[N+2],dp[N+2][N+2][N+2];
long mod;
long dfs(int nn,int mm,int bb)
{
  if(mm>m)return 0;
  if(bb>b)return 0;
  if(nn>n)
  {
    if(mm!=m)return 0;
    return 1;
  }
  if(dp[nn][mm][bb]!=-1)return dp[nn][mm][bb]*1LL;
  long here=0;
  for(int i=0;i<=m;i++)
    here=(here+dfs(nn+1,mm+i,bb+i*arr[nn]))%mod;
  return dp[nn][mm][bb]=here%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>b>>mod;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0,0)<<endl;
   return 0;
}