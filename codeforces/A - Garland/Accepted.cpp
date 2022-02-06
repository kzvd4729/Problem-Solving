/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/05/2020 20:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 8300 KB                              
*  problem: https://codeforces.com/contest/1286/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2,inf=1e9;
int n,aa[N+2],dp[N+2][N+2][N+2][2],vis[N+2];
int dfs(int i,int od,int ev,int l)
{
  if(i>n)return 0;int ret=inf;
  if(dp[i][od][ev][l]!=-1)return dp[i][od][ev][l];
  if(aa[i])
  {
    ret=0;
    if(l!=aa[i]%2)ret++;
    return dp[i][od][ev][l]=ret+dfs(i+1,od,ev,aa[i]%2);
  }
  else
  {
    if(l)
    {
      if(od)ret=min(ret,dfs(i+1,od-1,ev,1));
      if(ev)ret=min(ret,1+dfs(i+1,od,ev-1,0));
    }
    else
    {
      if(od)ret=min(ret,1+dfs(i+1,od-1,ev,1));
      if(ev)ret=min(ret,dfs(i+1,od,ev-1,0));
    }
    return dp[i][od][ev][l]=ret;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i],vis[aa[i]]=1;
   int f=0;
  for(int i=1;i<=n;i++)if(aa[i]==0)f=1;
   if(f==0)
  {
    int ans=0;
    for(int i=2;i<=n;i++)
      if(aa[i]%2!=aa[i-1]%2)ans++;
    cout<<ans<<endl,exit(0);
  }
   int ev=0,od=0;
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    if(i%2==0)ev++;else od++;
  }
   memset(dp,-1,sizeof(dp));
  if(aa[1])
  {
    cout<<dfs(2,od,ev,aa[1]%2)<<endl;
  }
  else
  {
    int ans=inf;
    if(od)ans=min(ans,dfs(2,od-1,ev,1));
    if(ev)ans=min(ans,dfs(2,od,ev-1,0));
    cout<<ans<<endl;
  }
  return 0;
}