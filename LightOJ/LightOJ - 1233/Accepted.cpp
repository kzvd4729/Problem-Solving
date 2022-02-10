/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-14 19:57:45                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1717                                       memory_used (MB): 3.5                             
*  problem: https://vjudge.net/problem/LightOJ-1233
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int aa[102],bb[102];
bitset<100001>dp[102];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
      cin>>aa[i];
    for(int i=1;i<=n;i++)
      cin>>bb[i];
    for(int i=0;i<=n;i++)dp[i].reset();
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
      int vl=0;dp[i]=dp[i-1];
      for(int j=1;j<=bb[i];j++)
      {
        vl+=aa[i];if(vl>m)break;
        dp[i]|=(dp[i-1]<<vl);
      }
    }
    int ans=0;
    for(int i=1;i<=m;i++)
      ans+=dp[n][i];
    cout<<"Case "<<++tc<<": "<<ans<<"\n";
  }
  return 0;
}