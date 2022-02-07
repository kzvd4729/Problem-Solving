/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-17 15:12:14                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 90                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10130
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,n,pr[1002],wg[1002],cp[102],dp[1002][40],pp;
int _find(int cs)
{
  memset(dp,0,sizeof(dp));
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=cs;j++)
    {
      dp[i][j]=dp[i-1][j];
      if(wg[i]<=j)
        dp[i][j]=max(dp[i][j],dp[i-1][j-wg[i]]+pr[i]);
    }
  }
  return dp[n][cs];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>pr[i]>>wg[i];
    cin>>pp;
    for(int i=1;i<=pp;i++)
      cin>>cp[i];
    int ans=0;
    for(int i=1;i<=pp;i++)
      ans+=_find(cp[i]);
    cout<<ans<<endl;
  }
  return 0;
}