/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-22 19:08:08                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 44                                         memory_used (MB): 2.5                             
*  problem: https://vjudge.net/problem/LightOJ-1125
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long mod,t,q,tc,n,arr[1003],m,dp[202][22][22],tmp[202];
int main()
{
  //ofstream cout("out.txt");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  cin>>t;
  while(t--)
  {
    cin>>n>>q;
    for(int i=1;i<=n;i++)
      cin>>tmp[i];
    cout<<"Case "<<++tc<<":"<<endl;
    while(q--)
    {
      memset(dp,0,sizeof(dp));
      cin>>mod>>m;
      for(int i=1;i<=n;i++)
        arr[i]=((tmp[i]%mod)+mod)%mod;
      dp[0][0][0]=1;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
          for(int k=0;k<mod;k++)
          {
            int x=(k+arr[i+1])%mod;
            dp[i+1][j+1][x]+=dp[i][j][k];
            dp[i+1][j][k]+=dp[i][j][k];
          }
        }
      }
      long ans=0;
      for(int i=1;i<=n;i++)ans+=dp[i][m][0];
      cout<<ans<<endl;
    }
  }
  return 0;
}