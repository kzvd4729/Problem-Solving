/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2020 12:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 35500 KB                             
*  problem: https://codeforces.com/contest/1336/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e3,mod=998244353;
string s,t;int n,m,dp[N+2][N+2];
int dfs(int i,int j,int k)
{
  if(i>n){if(j<1&&k>m)return 1;return 0;}
  if(dp[j][k]!=-1)return dp[j][k];
  int ret=0;if(j<1&&k>m)ret=1;
  if((j>m||s[i]==t[j])&&(j>=1))ret=(ret+dfs(i+1,j-1,k))%mod;
  if((k>m||s[i]==t[k])&&(k<=n))ret=(ret+dfs(i+1,j,k+1))%mod;
  return dp[j][k]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>s>>t;n=s.size(),m=t.size();s="#"+s;t="&"+t;
  int ans=0;memset(dp,-1,sizeof(dp));
  for(int j=1;j<=n;j++)
  {
    if(j>m)ans=(1LL*ans+2*dfs(2,j-1,j+1))%mod;
    else if(s[1]==t[j])ans=(1LL*ans+2*dfs(2,j-1,j+1))%mod;
  }
  cout<<ans<<endl;
  return 0;
}