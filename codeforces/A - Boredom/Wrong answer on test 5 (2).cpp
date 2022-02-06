/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/26/2017 23:05                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/455/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[100005],dp[100005][2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    dp[1][1]=arr[1];
    for(long i=2;i<=n;i++)
    {
        dp[i][1]=max(dp[i-1][0],dp[i-2][1])+arr[i];
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
    }
    cout<<max(dp[n][1],dp[n][0])<<endl;
     return 0;
}