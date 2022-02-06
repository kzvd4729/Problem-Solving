/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 312 ms                                          memory_used: 196100 KB                            
*  problem: https://codeforces.com/contest/1114/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
int n,aa[N+2],dp[N+1][N+1][2];
int dfs(int lo,int hi,int f)
{
  if(lo==1&&hi==n)return 0;
  if(dp[lo][hi][f]!=-1)return dp[lo][hi][f];
  int cl,now=1e9;
  if(!f)cl=aa[lo];else cl=aa[hi];
  if(hi<n)
  {
    if(cl==aa[hi+1])
      now=min(now,dfs(lo,hi+1,1));
    else now=min(now,1+dfs(lo,hi+1,1));
  }
  if(lo>1)
  {
    if(cl==aa[lo-1])
      now=min(now,dfs(lo-1,hi,0));
    else now=min(now,1+dfs(lo-1,hi,0));
  }
  return dp[lo][hi][f]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  int ans=1e9;memset(dp,-1,sizeof(dp));
  for(int i=1;i<=n;i++)
    ans=min(ans,dfs(i,i,1));
  cout<<ans<<endl;
  return 0;
}