/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2018 17:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1435 ms                                         memory_used: 4000 KB                              
*  problem: https://codeforces.com/contest/543/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=5e2;
long mod,dp[2][N+2][N+2];
int n,m,b,arr[N+2];
long ck(int i,int j,int k)
{
  if(i<0||j<0||k<0)return 0;
  if(i==0&&j==0&&k==0)return 1;
  return dp[i%2][j][k];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>b>>mod;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  for(int i=1;i<=n;i++)
    for(int j=0;j<=b;j++)
      for(int k=0;k<=m;k++)
        dp[i%2][j][k]=(ck(i-1,j,k)+ck(i,j-arr[i],k-1))%mod;
  long ans=0;
  for(int i=0;i<=b;i++)
    ans=(ans+ck(n,i,m))%mod;
  cout<<ans<<endl;
  return 0;
}