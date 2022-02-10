/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-26 23:39:32                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 12                                         memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1064
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long dp[30][160],n,x,t,tc;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>x;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=6;i++)dp[1][i]=1;
    for(int i=2;i<=n;i++)
    {
      for(int vl=1;vl<=6;vl++)
      {
        for(int last=1;last<=150;last++)
        {
          dp[i][vl+last]+=dp[i-1][last];
        }
      }
    }
    long up=0,dw=0;
    for(int i=1;i<=150;i++)
    {
      if(i>=x)up+=dp[n][i];
      dw+=dp[n][i];
    }
    long gcd=__gcd(up,dw);
    up/=gcd;
    dw/=gcd;
    cout<<"Case "<<++tc<<": ";
    if(dw==1)cout<<up<<endl;
    else cout<<up<<"/"<<dw<<endl;
  }
  return 0;
}