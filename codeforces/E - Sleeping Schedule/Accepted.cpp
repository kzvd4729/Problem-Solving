/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/12/2020 19:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 19700 KB                             
*  problem: https://codeforces.com/contest/1324/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],n,h,l,r,dp[2000+2][2000+2];
int dfs(int i,int nw)
{
  if(dp[i][nw]!=-1)return dp[i][nw];
  int ret=0;
  if(nw>=l&&nw<=r)ret++;
  if(i>n)return dp[i][nw]=ret;
  ret+=max(dfs(i+1,(nw+aa[i])%h),dfs(i+1,(nw+aa[i]-1+h)%h));
  return dp[i][nw]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>h>>l>>r;
  for(int i=1;i<=n;i++)cin>>aa[i];
  memset(dp,-1,sizeof(dp));
  cout<<max(dfs(2,aa[1]),dfs(2,aa[1]-1))<<endl;
    return 0;
}