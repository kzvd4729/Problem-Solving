/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-06-28 22:22:35                      
*  solution_verdict: Wrong answer #1                         language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-DSUBSEQ
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int mod=1000000007;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;s="#"+s;
    int n=s.size();vector<int>dp(n,0),lst(400,-1);
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
      dp[i]=(dp[i-1]+dp[i-1])%mod;
      int c=(int)s[i];
      if(lst[c]!=-1)
        dp[i]=(dp[i]-dp[lst[c]-1])%mod;
      lst[c]=i;
    }
    cout<<dp[n-1]<<"\n";
  }
  return 0;
}