/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-29 19:19:45                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-COLORSEG
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50,mod=1000003;
int dp[N+2][N+2][N+2][N+2],n,m,mt[N+2][N+2][N+2];
int dfs(int i,int a,int b)
{
  if(i==0)return 1;
  if(dp[m][i][a][b]!=-1)return dp[m][i][a][b];
  int now=0;
  for(int j=1;j<=m;j++)
    if(mt[j][a][b])now=(now+dfs(i-1,j,a))%mod;
  return dp[m][i][a][b]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=1;i<=50;i++)
  {
    for(int j=1;j<=50;j++)
      for(int k=1;k<=50;k++)
        if(__gcd(i+j,j+k)==1)mt[i][j][k]=1;
  }
  int t,tc=0;cin>>t;memset(dp,-1,sizeof(dp));
  while(t--)
  {
    cin>>n>>m;cout<<"Case "<<++tc<<": ";
    if(n<3)cout<<0<<"\n";
    else
    {
      int ans=0;
      for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
          ans=(ans+dfs(n-2,i,j))%mod;
      cout<<ans<<"\n";
    }
  }
  return 0;
}