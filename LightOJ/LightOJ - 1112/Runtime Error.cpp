/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-22 19:07:27                      
*  solution_verdict: Runtime Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1112
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long dp[12][12],vis[12],x,tc,t,m,n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  cin>>t;
  while(t--)
  {
    cin>>m>>n;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=m;i++)
      cin>>x,vis[x]=1;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=9;i++)
      if(vis[i]==1)dp[1][i]=1;
 
    for(int i=2;i<=n;i++)
    {
      for(int now=1;now<=9;now++)
      {
        if(vis[now]==0)continue;
        for(int last=1;last<=9;last++)
        {
          if(vis[last]==0||abs(now-last)>2)continue;
          dp[i][now]+=dp[i-1][last];
        }
      }
    }
    long ans=0;
    for(int i=1;i<=9;i++)ans+=dp[n][i];
    cout<<"Case "<<++tc<<": "<<ans<<endl;
  }
  return 0;
}
 