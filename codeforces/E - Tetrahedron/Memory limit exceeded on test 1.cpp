/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/22/2018 10:17                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++                                 
*  run_time: 0 ms                                            memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/166/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1000000007;
long n,dp[10000002][4];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    dp[1][2]=1;
    dp[1][3]=1;
    dp[1][4]=1;
     for(long i=2;i<=n;i++)
    {
        dp[i][1]=(dp[i-1][2]+dp[i-1][3]+dp[i-1][4])%mod;
        dp[i][2]=(dp[i-1][1]+dp[i-1][3]+dp[i-1][4])%mod;
        dp[i][3]=(dp[i-1][1]+dp[i-1][4]+dp[i-1][2])%mod;
        dp[i][4]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%mod;
    }
    cout<<dp[n][1]<<endl;
    return 0;
}