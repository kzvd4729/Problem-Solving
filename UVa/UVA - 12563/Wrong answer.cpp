/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-12-06 15:16:19                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12563
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[55],dp[55][10000],n,tme,song,t,ttm,tc;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>n>>ttm;
        memset(dp,-1,sizeof(dp));
        for(long i=1;i<=n;i++)cin>>arr[i];
        dp[0][0]=0;
        for(long i=1;i<=n;i++)
        {
            for(long j=0;j<min(ttm,9000LL);j++)
            {
                if(dp[i-1][j]==-1||j+arr[i]>=ttm||j+arr[i]>=9000)continue;
                dp[i][j+arr[i]]=max(dp[i][j+arr[i]],dp[i-1][j]+1);
            }
            for(long j=0;j<min(ttm,9000LL);j++)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
        }
        song=0,tme=0;
        for(long i=1;i<=n;i++)
        {
            for(long j=0;j<min(ttm,9000LL);j++)
            {
                if(dp[i][j]>=song)
                {
                    song=dp[i][j];
                    tme=max(tme,j);
                }
            }
        }
        cout<<"Case "<<++tc<<": "<<song+1<<" "<<tme+678<<endl;
    }
    return 0;
}