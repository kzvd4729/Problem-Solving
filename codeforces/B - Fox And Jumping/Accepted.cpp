/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/10/2018 22:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 17700 KB                             
*  problem: https://codeforces.com/contest/512/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e2;
int ll[N+2],cc[N+2],n;
map<int,int>dp[N+2];
int dfs(int st,int gcd)
{
  if(gcd==1)return 0;
  if(st>n)return 2e9;
  if(dp[st][gcd])return dp[st][gcd];
  return dp[st][gcd]=min(cc[st]+dfs(st+1,__gcd(gcd,ll[st])),dfs(st+1,gcd));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;for(int i=1;i<=n;i++)cin>>ll[i];
  for(int i=1;i<=n;i++)cin>>cc[i];
  int ans=dfs(1,0);if(ans>1000000000)ans=-1;
  cout<<ans<<endl;
  return 0;
}