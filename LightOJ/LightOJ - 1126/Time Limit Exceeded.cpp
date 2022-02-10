/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-13 21:49:46                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1126
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=500000;
const int con=N/2;
int aa[N+2],n;
int dp[2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    int id=(n+1)%2,di;
    for(int df=-con;df<=con;df++)
      dp[id][df+con]=-1e7;
    dp[id][con]=0;
    for(int i=n;i>=1;i--)
    {
      id^=1;di=id^1;
      for(int df=-con;df<=con;df++)
      {
        dp[id][df+con]=dp[di][df+con];
        if(df+aa[i]+con<=N)
          dp[id][df+con]=max(dp[id][df+con],aa[i]+dp[di][df+aa[i]+con]);
        if(df-aa[i]+con>=0)
          dp[id][df+con]=max(dp[id][df+con],dp[di][df-aa[i]+con]);
      }
    }
    int ans=dp[1][con];
    if(ans<=0)cout<<"Case "<<++tc<<": impossible"<<"\n";
    else cout<<"Case "<<++tc<<": "<<ans<<"\n";
  }
  return 0;
}