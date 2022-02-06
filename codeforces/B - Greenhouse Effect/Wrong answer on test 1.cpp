/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/05/2017 00:22                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 196100 KB                            
*  problem: https://codeforces.com/contest/269/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,arr[5005],dp[5005][5005],ans=0;
double zz;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i];
        cin>>zz;
    }
    dp[1][1]=1;
    for(long i=2;i<=n;i++)
    {
        for(long j=1;j<i;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(arr[i]>=arr[j])dp[i][i]=max(dp[i][i],dp[i-1][j]+1);
        }
        ans=max(ans,dp[i][i]);
    }
    cout<<n-ans<<endl;
    return 0;
}