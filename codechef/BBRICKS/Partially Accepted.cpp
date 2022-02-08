/****************************************************************************************
*  @author: kzvd4729                                         created: 07-10-2018 16:40:41                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.07 sec                                        memory_used: 45.5M                                
*  problem: https://www.codechef.com/OCT18A/problems/BBRICKS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const long mod=1e9+7;
int n,k;long dp[N+2][N+2][2][2];
long dfs(int st,int kk,int on,int tw)
{
  if(st>n)
  {
    if(kk==k)return 1;
    else return 0;
  }
  if(dp[st][kk][on][tw]!=-1)return dp[st][kk][on][tw];
  long here=0;
  here=(here+dfs(st+1,kk,0,0))%mod;
  if(!on)here=(here+dfs(st+1,kk+1,1,0))%mod;
  if(!tw)here=(here+dfs(st+1,kk+1,0,1))%mod;
  return dp[st][kk][on][tw]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>k;memset(dp,-1,sizeof(dp));
    cout<<dfs(1,0,0,0)<<endl;
  }
  return 0;
}