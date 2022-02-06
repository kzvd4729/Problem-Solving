/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/27/2018 14:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 405 ms                                          memory_used: 157300 KB                            
*  problem: https://codeforces.com/contest/383/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const int N=1e3;
const int R=1e4;
int n,arr[N+2];
int dp[2][N+2][R+R+2];
long dfs(int f,int st,int s)
{
  if(st>n)
  {
    if(f&&!s)return 1;
    else return 0;
  }
  if(dp[f][st][s+R]!=-1)return dp[f][st][s+R]*1LL;
  long here=0;
  if(f&&!s)here=1;
  if(!f)here=(here+dfs(f,st+1,s))%mod;
  here=(here+dfs(1,st+1,s+arr[st]))%mod;
  here=(here+dfs(1,st+1,s-arr[st]))%mod;
  dp[f][st][s+R]=(here%mod);
  return dp[f][st][s+R]*1LL;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
   memset(dp,-1,sizeof(dp));
  cout<<dfs(0,1,0)<<endl;
   return 0;
}