/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-25 00:03:56                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 432                                        memory_used (MB): 2.2                             
*  problem: https://vjudge.net/problem/LightOJ-1274
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
double dp[2][5000+2][2];
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n,s;cin>>n>>s;int a,b;
    for(int i=0;i<=n;i++)
    {
      if(i*2+(n-i)*3==s)
      {
        a=i,b=n-i;break;
      }
    }
    memset(dp,0,sizeof(dp));
    int i=0,j=1;
    for(int tw=0;tw<=a;tw++)
    {
      memset(dp[i],0,sizeof(dp[i]));
      for(int th=0;th<=b;th++)
      {
        if(th)dp[i][th][0]+=(th*1.0)/(tw+th)*(1+dp[i][th-1][1]);
        if(tw)dp[i][th][0]+=(tw*1.0)/(tw+th)*dp[j][th][0];

        if(th)dp[i][th][1]+=(th*1.0)/(tw+th)*dp[i][th-1][1];
        if(tw)dp[i][th][1]+=(tw*1.0)/(tw+th)*(1+dp[j][th][0]);
      }
      swap(i,j);
    }
    cout<<"Case "<<++tc<<": "<<setprecision(10)<<fixed<<dp[a%2][b][1]<<"\n";
  }
  return 0;
}