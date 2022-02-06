/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/16/2018 16:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 607 ms                                          memory_used: 41100 KB                             
*  problem: https://codeforces.com/contest/580/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=20;
int n,m,k,aa[N+2],mat[N+2][N+2];
long dp[(1<<18)+2][20];
long dfs(int msk,int last)
{
  if(__builtin_popcount(msk)==m)return 0;
  if(dp[msk][last]!=-1)return dp[msk][last];
  long here=0;
  for(int i=0;i<n;i++)
  {
    if(msk&(1<<i))continue;
    here=max(here,aa[i]*1LL+mat[last][i]*1LL+dfs(msk|(1<<i),i));
  }
  return dp[msk][last]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>k;
  for(int i=0;i<n;i++)cin>>aa[i];
  while(k--)
  {
    int x,y,c;cin>>x>>y>>c;
    mat[--x][--y]=c;
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,19)<<endl;
  return 0;
}