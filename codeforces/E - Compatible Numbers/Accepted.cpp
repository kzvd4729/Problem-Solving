/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/18/2018 18:27                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 1404 ms                                         memory_used: 78500 KB                             
*  problem: https://codeforces.com/contest/165/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e6;
int dp[2][N+N+2],aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];dp[1][aa[i]]=aa[i];
  }
  for(int j=0;j<=21;j++)
  {
    for(int i=0;i<=(1<<22)-1;i++)
    {
      if(i&(1<<j))
        dp[j%2][i]=max(dp[(j+1)%2][i],dp[(j+1)%2][i^(1<<j)]);
      else dp[j%2][i]=dp[(j+1)%2][i];
    }
  }
  for(int i=1;i<=n;i++)
  {
    int tmp=0;
    for(int j=0;j<=21;j++)
      if(!(aa[i]&(1<<j)))tmp|=(1<<j);
    int xx=dp[1][tmp];
    if(xx==0)xx=-1;
    cout<<xx<<" ";
  }
  return 0;
}