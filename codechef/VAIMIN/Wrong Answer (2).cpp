/****************************************************************************************
*  @author: kzvd4729                                         created: 10-04-2018 13:31:20                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 152.5M                               
*  problem: https://www.codechef.com/APRIL18A/problems/VAIMIN
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
long dp[3003][3003],p,q,c,m,x,y,vis[3003][3003];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>p>>q>>c>>m;
  while(m--)
  {
    cin>>x>>y;
    if(x>3000||y>3000)continue;
    vis[x][y]=1;
  }
  for(int i=1;i<=p;i++)
  {
    if(vis[i][0])continue;
    dp[i][0]=1;
  }
  for(int j=1;j<=q;j++)
  {
    for(int i=c+1;i<=p;i++)
    {
      if(vis[i][j]||i-j<c)continue;
      dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
    }
  }
  cout<<dp[p][q]%mod<<endl;
//  for(int i=0;i<=p;i++)
//  {
//    for(int j=0;j<=q;j++)
//    {
//      cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
//    }
//  }
  return 0;
}