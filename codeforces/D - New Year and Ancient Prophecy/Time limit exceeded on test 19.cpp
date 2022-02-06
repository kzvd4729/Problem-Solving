/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2020 18:09                        
*  solution_verdict: Time limit exceeded on test 19          language: GNU C++14                               
*  run_time: 2500 ms                                         memory_used: 97900 KB                             
*  problem: https://codeforces.com/contest/611/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3,mod=1e9+7;
string s;
bool ret(int i,int j,int k)
{
  if(i<=0)return false;
  if(s[i]=='0')return false;
  for(int l=0;l<k;l++)
    if(s[i+l]!=s[j+l])return s[i+l]<s[j+l];
  return false;
}
int dp[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n>>s;s="#"+s;
   for(int i=0;i<=n;i++)dp[0][i]=1;
  for(int i=1;i<=n;i++)
  {
    for(int l=1;l<=n;l++)
    {
      dp[i][l]=dp[i][l-1];
      if(i-l<0||s[i-l+1]=='0')continue;
      dp[i][l]=(dp[i][l]+dp[i-l][l-1])%mod;
      if(ret(i-l-l+1,i-l+1,l))dp[i][l]=(dp[i][l]+dp[i-l][l]-dp[i-l][l-1])%mod;
       if(dp[i][l]<0)dp[i][l]+=mod;
    }
  }
  cout<<dp[n][n]<<endl;
  return 0;
}