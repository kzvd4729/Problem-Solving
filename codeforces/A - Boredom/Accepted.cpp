/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/26/2017 23:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/455/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[100005],dp[100005][2],x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        arr[x]+=x;
    }
    dp[1][1]=arr[1];
    for(long i=2;i<=100000;i++)
    {
        dp[i][1]=dp[i-1][0]+arr[i];
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
    }
    cout<<max(dp[100000][1],dp[100000][0])<<endl;
     return 0;
}