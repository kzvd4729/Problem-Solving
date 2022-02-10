/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-30 19:47:56                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 282                                        memory_used (MB): 10.4                            
*  problem: https://vjudge.net/problem/LightOJ-1223
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
long dp[N+2][N+2][N+2];
long dfs(int k,int lo,int hi)
{
  if(lo>hi)return 0;if(k==0)return 1e18;
  if(dp[k][lo][hi]!=-1)return dp[k][lo][hi];
  long now=1e18;
  for(int i=lo;i<=hi;i++)
    now=min(now,max(dfs(k,i+1,hi),dfs(k-1,lo,i-1))+i);
  return dp[k][lo][hi]=now;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;memset(dp,-1,sizeof(dp));
  while(t--)
  {
    int k,m;cin>>k>>m;
    cout<<"Case "<<++tc<<": "<<dfs(k,1,m)<<"\n";
  }
  return 0;
}