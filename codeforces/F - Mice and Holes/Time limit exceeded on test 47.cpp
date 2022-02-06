/****************************************************************************************
*  @author: kzvd4729                                         created: May/09/2019 19:47                        
*  solution_verdict: Time limit exceeded on test 47          language: GNU C++14                               
*  run_time: 1500 ms                                         memory_used: 196200 KB                            
*  problem: https://codeforces.com/contest/797/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5000;
int n,m,aa[N+2];
long dp[N+2][N+2];
pair<int,int>pp[N+2];
long dfs(int hl,int mc)
{
  if(mc>n)return 0;if(hl>m)return 1e18;
  if(dp[hl][mc]!=-1)return dp[hl][mc];
  long now=dfs(hl+1,mc),sm=0;
  for(int i=1;i<=pp[hl].second;i++)
  {
    if(mc+i-1>n)break;
    sm+=abs(aa[mc+i-1]-pp[hl].first);
    now=min(now,sm+dfs(hl+1,mc+i));
  }
  return dp[hl][mc]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=1;i<=m;i++)
    cin>>pp[i].first>>pp[i].second;
  sort(pp+1,pp+m+1);sort(aa+1,aa+n+1);
  memset(dp,-1,sizeof(dp));
  long ans=dfs(1,1);if(ans==1e18)ans=-1;
  cout<<ans<<endl;
   return 0;
}