/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/26/2017 23:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/189/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,a,b,c,dp[40004];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n>>a>>b>>c;
    dp[0]=0;
    for(long i=1;i<=n;i++)
    {
        if(i-a>=0)if(dp[i-a]!=-1)dp[i]=max(dp[i],dp[i-a]+1);
        if(i-b>=0)if(dp[i-b]!=-1)dp[i]=max(dp[i],dp[i-b]+1);
        if(i-c>=0)if(dp[i-c]!=-1)dp[i]=max(dp[i],dp[i-c]+1);
    }
    cout<<dp[n]<<endl;
    return 0;
}