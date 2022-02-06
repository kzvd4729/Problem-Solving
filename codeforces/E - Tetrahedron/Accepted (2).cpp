/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/22/2018 10:22                        
*  solution_verdict: Accepted                                language: GNU C++                                 
*  run_time: 716 ms                                          memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/166/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1000000007;
long n,dp[4][4];
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
        dp[i%2][1]=(dp[(i+1)%2][2]+dp[(i+1)%2][3]+dp[(i+1)%2][4])%mod;
        dp[i%2][2]=(dp[(i+1)%2][1]+dp[(i+1)%2][3]+dp[(i+1)%2][4])%mod;
        dp[i%2][3]=(dp[(i+1)%2][1]+dp[(i+1)%2][4]+dp[(i+1)%2][2])%mod;
        dp[i%2][4]=(dp[(i+1)%2][1]+dp[(i+1)%2][2]+dp[(i+1)%2][3])%mod;
    }
    cout<<dp[n%2][1]<<endl;
    return 0;
}