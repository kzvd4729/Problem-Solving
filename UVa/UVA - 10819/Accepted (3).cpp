/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-20 21:42:24                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 110                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10819
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int m,n,dp[102][14000],mn[102],fv[102],ans;
int main()
{
  ///ofstream cout("out.txt");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while(cin>>m>>n)
  {
    for(int i=1;i<=n;i++)cin>>mn[i]>>fv[i];
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    ans=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=0;j<=m+200;j++)dp[i][j]=dp[i-1][j];
      for(int j=0;j<=m+200;j++)
      {
        if(dp[i-1][j]==-1)continue;
        int x=j+mn[i];
        if(x<=m+200)dp[i][x]=max(dp[i][x],dp[i-1][j]+fv[i]);
        if(x<=m||(x<=(m+200)&&x>2000))ans=max(ans,dp[i][x]);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}