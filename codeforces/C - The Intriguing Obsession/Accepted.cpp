/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/19/2020 10:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 296 ms                                          memory_used: 98100 KB                             
*  problem: https://codeforces.com/contest/869/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3,mod=998244353;
int dp[N+2][N+2];
int dfs(int a,int b)
{
  if(a==0)return 1;
  if(dp[a][b]!=-1)return dp[a][b];
  int ret=dfs(a-1,b);
  ret=(1LL*ret+1LL*b*dfs(a-1,b-1))%mod;
  return dp[a][b]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b,c;cin>>a>>b>>c;int ans=1;
  memset(dp,-1,sizeof(dp));
  ans=(1LL*ans*dfs(min(a,b),max(a,b)))%mod;
  ans=(1LL*ans*dfs(min(b,c),max(b,c)))%mod;
  ans=(1LL*ans*dfs(min(c,a),max(c,a)))%mod;
  cout<<ans<<endl;
    return 0;
}