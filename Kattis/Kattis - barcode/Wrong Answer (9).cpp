/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-12 17:13:41                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-barcode
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int m,dp[N+2][2];
int dfs(int n,int f)
{
  if(n==0)return 1;
  if(dp[n][f]!=-1)return dp[n][f];
  if(f)return dfs(n-1,0);
  return dp[n][f]=(dfs(n-1,0)+dfs(n-1,1))%m;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    cout<<dfs(n,0)<<"\n";
  }  
  return 0;
}