/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2019 01:21                        
*  solution_verdict: Time limit exceeded on test 2           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/598/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int dp[32][32][52];
int dfs(int n,int m,int k)
{
  if(n*m<k)return 1e9;if(n*m==k||!k)return 0;
  int now=1e9;
  for(int i=1;i<n;i++)
    for(int j=0;j<=k;j++)
      now=min(now,m*m+dfs(i,m,j)+dfs(n-i,m,k-j));
  for(int i=1;i<m;i++)
    for(int j=0;j<=k;j++)
      now=min(now,n*n+dfs(n,i,j)+dfs(n,m-i,k-j));
  return now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;memset(dp,-1,sizeof(dp));
  while(t--)
  {
    int n,m,k;cin>>n>>m>>k;
    cout<<dfs(n,m,k)<<"\n";
  }
  return 0;
}