/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/10/2018 19:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 872 ms                                          memory_used: 195900 KB                            
*  problem: https://codeforces.com/contest/163/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
const long mod=1e9+7;
long dp[N+2][N+2],ans;
string a,b;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b;
  for(int i=a.size()-1;i>=0;i--)
  {
    for(int j=b.size()-1;j>=0;j--)
    {
      dp[i][j]=dp[i][j+1];
      if(a[i]==b[j])dp[i][j]=(dp[i][j]+dp[i+1][j+1]+1)%mod;
    }
    ans=(ans+dp[i][0])%mod;
  }
  cout<<ans<<endl;
  return 0;
}