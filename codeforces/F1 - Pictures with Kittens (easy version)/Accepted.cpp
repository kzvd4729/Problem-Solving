/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/16/2018 21:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 64500 KB                             
*  problem: https://codeforces.com/contest/1077/problem/F1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2;
const long inf=1e14;
int n,k,x,aa[N+2];
long dp[N+2][N+2][N+2];
long dfs(int st,int last,int tk)
{
  if(st-last>k)return -inf;
  if(st>n)
  {
    if(tk==x)return 0;
    return -inf;
  }
  if(dp[st][last][tk]!=-1)return dp[st][last][tk];
  long here=-inf;
  here=max(here,aa[st]+dfs(st+1,st,tk+1));
  here=max(here,dfs(st+1,last,tk));
  return dp[st][last][tk]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k>>x;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  memset(dp,-1,sizeof(dp));
  long ans=dfs(1,0,0);
  if(ans<0)ans=-1;
  cout<<ans<<endl;
  return 0;
}