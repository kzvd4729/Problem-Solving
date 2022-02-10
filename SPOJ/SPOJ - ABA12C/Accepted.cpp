/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-12-21 19:01:27                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 15.4                            
*  problem: https://vjudge.net/problem/SPOJ-ABA12C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 99999999
using namespace std;
long t,n,k,arr[102],dp[102][102];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(long i=1;i<=k;i++)cin>>arr[i];
        for(long i=0;i<=100;i++)
        {
            for(long j=0;j<=100;j++)dp[i][j]=inf;
        }
        for(long i=0;i<=n;i++)dp[i][0]=0;
        for(long i=1;i<=n;i++)
        {
            for(long j=0;j<=k;j++)
            {
                for(long id=1;id<=k;id++)
                {
                    if(arr[id]==-1)continue;
                    if(j+id>k)continue;
                    if(dp[i-1][j]==inf)continue;
                    dp[i][j+id]=min(dp[i][j+id],dp[i-1][j]+arr[id]);
                }
            }
        }
        if(dp[n][k]==inf)dp[n][k]=-1;
        cout<<dp[n][k]<<endl;
    }
    return 0;
}