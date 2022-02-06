/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/27/2018 16:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 197300 KB                            
*  problem: https://codeforces.com/contest/999/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,k,fre[N+2],vis[N+2],hh[12];
int ans,x,dp[502][N+2];
 int dfs(int st,int card)
{
  if(st<1)return 0;
  if(dp[st][card]!=-1)return dp[st][card];
  int here=0;
  for(int i=0;i<=min(card,k);i++)
    here=max(here,hh[i]+dfs(st-1,card-i));
  return dp[st][card]=here;
}
 int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n*k;i++)
  {
    cin>>x;
    fre[x]++;
  }
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    vis[x]++;
  }
  for(int i=1;i<=k;i++)
    cin>>hh[i];
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=N;i++)
    if(vis[i])
      ans+=dfs(vis[i],fre[i]);
   cout<<ans<<endl;
   return 0;
}