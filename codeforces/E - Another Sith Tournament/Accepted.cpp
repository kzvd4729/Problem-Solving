/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/27/2019 00:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 483 ms                                          memory_used: 61700 KB                             
*  problem: https://codeforces.com/contest/678/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=18;
int n,vis[(1<<18)+2][20];
double p[N+2][N+2],dp[(1<<18)+2][20];
double dfs(int msk,int l)
{
  if(vis[msk][l])return dp[msk][l];
  if(__builtin_popcount(msk)==n)
  {
    if(l==0)return 1.0;
    else return 0.0;
  }
  double now=0;
  for(int i=0;i<n;i++)
  {
    if((msk&(1<<i)))continue;
    now=max(now,p[l][i]*dfs(msk|(1<<i),l)+p[i][l]*dfs(msk|(1<<i),i));
  }
  vis[msk][l]=1;
  return dp[msk][l]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>p[i][j];
  double ans=0;int msk=0;
  for(int i=0;i<n;i++)
    ans=max(ans,dfs(msk|(1<<i),i));
  cout<<setprecision(10)<<fixed<<ans<<endl;
  return 0;
}