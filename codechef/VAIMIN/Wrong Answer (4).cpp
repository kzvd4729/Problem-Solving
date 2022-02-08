/****************************************************************************************
*  @author: kzvd4729                                         created: 10-04-2018 15:30:43                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 152.5M                               
*  problem: https://www.codechef.com/APRIL18A/problems/VAIMIN
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
long dp[3003][3003],p,q,m,x,y,c,vis[3003][3003];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>p>>q>>c>>m;
  for(int i=1;i<=p;i++)dp[i][0]=1;
  while(m--)
  {
    cin>>x>>y;
    if(x>3000||y>3000)continue;
    dp[x][y]=0;
    vis[x][y]=1;
  }
  for(int i=1;i<=p;i++)
  {
    for(int j=1;j<=q;j++)
    {
      if(vis[i][j])continue;
      if(i-j<c)dp[i][j]=dp[i-1][j];
      else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
    }
  }
  cout<<dp[p][q]%mod<<endl;
  return 0;
}