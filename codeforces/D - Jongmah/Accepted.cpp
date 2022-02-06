/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 389 ms                                          memory_used: 164300 KB                            
*  problem: https://codeforces.com/contest/1110/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int fr[N+5],n,m,dp[N+5][5][5];
int dfs(int st,int a,int b)
{
  if(st>m)return 0;int now=0;
  if(dp[st][a][b]!=-1)return dp[st][a][b];
  now=max(now,(fr[st]-a)/3+dfs(st+1,b,0));
  if(fr[st]-a>0&&fr[st+1]-b>0&&fr[st+2])
    now=max(now,(fr[st]-a-1)/3+1+dfs(st+1,b+1,1));
  if(fr[st]-a>1&&fr[st+1]-b>1&&fr[st+2]>1)
    now=max(now,(fr[st]-a-2)/3+2+dfs(st+1,b+2,2));
  return dp[st][a][b]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;fr[x]++;
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0,0)<<endl;
  return 0;
}