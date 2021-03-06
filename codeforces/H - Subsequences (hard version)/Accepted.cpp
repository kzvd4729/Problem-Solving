/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/28/2019 22:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1183/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
#define long unsigned long long
using namespace std;
const int N=1e6;
long dp[102][102];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,k;cin>>n>>k;dp[0][0]=1;
  string s;cin>>s;s="#"+s;vector<int>lst(30,0);
  for(int i=1;i<=n;i++)
  {
    dp[i][0]=dp[i-1][0];int c=s[i]-'a';
    for(int j=1;j<=n;j++)
    {
      dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
      if(lst[c])dp[i][j]-=dp[lst[c]-1][j-1];
    }
    lst[c]=i;
  }
  long ans=0;
  for(int i=n;i>=0;i--)
  {
    if(dp[n][i]>=k)
    {
      ans+=k*(n-i);
      cout<<ans<<endl,exit(0);
    }
    else
    {
      k-=dp[n][i];
      ans+=dp[n][i]*(n-i);
    }
  }
  cout<<-1<<endl;
  return 0;
}