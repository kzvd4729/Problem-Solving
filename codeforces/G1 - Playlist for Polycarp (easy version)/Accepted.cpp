/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/08/2019 02:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 94800 KB                             
*  problem: https://codeforces.com/contest/1185/problem/G1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1e9+7;
int aa[N+2],bb[N+2],n,dp[(1<<15)+2][3][226];
long dfs(int msk,int gn,int rm)
{
  if(rm<0)return 0;if(rm==0)return 1;
  if(dp[msk][gn][rm]!=-1)return dp[msk][gn][rm];
  long now=0;
  for(int i=0;i<n;i++)
  {
    if(bb[i]==gn)continue;
    if((msk&(1<<i)))continue;
    now=(now+dfs(msk|(1<<i),bb[i],rm-aa[i]))%mod;
  }
  return dp[msk][gn][rm]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>n>>t;
  for(int i=0;i<n;i++)cin>>aa[i]>>bb[i],bb[i]--;
  long ans=0;
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<n;i++)
    ans=(ans+dfs((1<<i),bb[i],t-aa[i]))%mod;
  cout<<ans<<endl;
  return 0;
}