/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/18/2017 11:55                        
*  solution_verdict: Runtime error on test 6                 language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 201500 KB                            
*  problem: https://codeforces.com/contest/366/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,k,arr[55],brr[55],dp[51][1000220];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1; i<=n; i++)cin>>arr[i];
    for(int i=1; i<=n; i++)cin>>brr[i],brr[i]*=k,brr[i]=arr[i]-brr[i];
     memset(dp,-1,sizeof(dp));
    for(int i=0; i<=50; i++)dp[i][500100]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=-500000; j<=500000; j++)
        {
            int k=j+500100;
            dp[i][k]=dp[i-1][k];
            if(dp[i-1][k-brr[i]]!=-1)dp[i][k]=max(dp[i][k],dp[i-1][k-brr[i]]+arr[i]);
        }
    }
    if(dp[n][500100]==0)dp[n][500100]=-1;
    cout<<dp[n][500100]<<endl;
    return 0;
}