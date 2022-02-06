/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/15/2020 21:04                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 20400 KB                             
*  problem: https://codeforces.com/contest/1304/problem/F1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int mt[50+2][20000+2],qm[50+2][20000+2],dp[50+2][20000+2];
int sf[50+2][20000+2],pr[50+2][20000+2];
int get(int i,int l,int r)
{
  int ret=qm[i][r];if(l>1)ret=-qm[i][l-1];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>mt[i][j];
      qm[i][j]=qm[i][j-1]+mt[i][j];
    }
  }
  int ans=0;
  for(int j=1;j<=m;j++)
  {
    dp[1][j]=get(1,j,j-k+1);
    ans=max(ans,dp[1][j]);
    pr[1][j]=max(pr[1][j-1],dp[1][j]);
  }
  for(int j=m;j>=1;j--)
    sf[1][j]=max(sf[1][j+1],dp[1][j]);
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      dp[i][j]=max(sf[i-1][j+1],pr[i-1][j-k]+get(i,j,j-k+1));
      for(int l=j;l>=j+k-1;l--)
      {
        dp[i][j]=max(dp[i][j],dp[i-1][l]+get(i,j,j-k+1)-get(i,l+1,j));
      }
      pr[i][j]=max(pr[i][j-1],dp[i][j]);
      ans=max(ans,dp[i][j]);
    }
    for(int j=m;j>=1;j--)
      sf[i][j]=max(sf[i][j+1],dp[i][j]);
  }
cout<<ans<<endl;
  return 0;
}