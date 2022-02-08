/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-05 19:00:17                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 37 ms                                           memory_used: 640 KB                               
*  problem: https://atcoder.jp/contests/abc104/tasks/abc104_c
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
const int N=1e3;
int vis[12],d,g,p[12],c[12],ex;
int dp[12][10002];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>d>>g;
  for(int i=1;i<=d;i++)
    cin>>p[i]>>c[i];
   for(int i=1;i<=d;i++)
  {
    for(int j=0;j<=10000;j++)
    {
      for(int k=0;k<=p[i];k++)
      {
        dp[i][j]=max(dp[i][j],dp[i-1][j]);
        if(k>j)continue;
        if(k==p[i])ex=c[i];
        else ex=0;
        dp[i][j]=max(dp[i][j],k*i*100+ex+dp[i-1][j-k]);
      }
    }
  }
  int ans=inf;
  for(int i=1;i<=d;i++)
  {
    for(int j=1;j<=10000;j++)
    {
      if(dp[i][j]>=g)ans=min(ans,j);
    }
  }
  cout<<ans<<endl;
  return 0;
}