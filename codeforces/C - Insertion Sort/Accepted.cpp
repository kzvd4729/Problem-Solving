/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 186 ms                                          memory_used: 195900 KB                            
*  problem: https://codeforces.com/contest/362/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
int dp[N+2][N+2][2],aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int cnt=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;aa[i]=x;
    for(int j=0;j<=x;j++)dp[i+1][j][0]=dp[i][j][0];
    for(int j=x+1;j<=n;j++)dp[i+1][j][0]=dp[i][j][0]+1;
     for(int j=0;j<x;j++)dp[i+1][j][1]=dp[i][j][1]+1;
    for(int j=x;j<=n;j++)dp[i+1][j][1]=dp[i][j][1];
    cnt+=dp[i][x][1];
  }
  int mn=1e9,ans=0;
  for(int i=1;i<=n;i++)
  {
    int bl=0;
    for(int j=i+1;j<=n;j++)
    {
      if(aa[j]>aa[i])bl++;
      else bl--;
      int now=cnt+bl;
      now=now+(dp[j][aa[j]][0]-dp[i+1][aa[j]][0]);
      now=now-(dp[j][aa[j]][1]-dp[i+1][aa[j]][1]);
      //cout<<i<<" "<<j<<" "<<now<<endl;
      if(now<mn)mn=now,ans=0;
      if(now==mn)ans++;
    }
  }
  cout<<mn<<" "<<ans<<endl;
  return 0;
}