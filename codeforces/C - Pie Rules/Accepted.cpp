/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/17/2017 11:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/859/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[55],sum,dp[55][2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1; i<=n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    for(long i=n;i>=1;i--)
    {
        dp[i][1]=max(dp[i+1][0]+arr[i],dp[i+1][1]);
        dp[i][0]=min(dp[i+1][0]+arr[i],dp[i+1][1]);
    }
    cout<<sum-dp[1][1]<<" "<<dp[1][1]<<endl;
    return 0;
}
 