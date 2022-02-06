/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/02/2017 23:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 483 ms                                          memory_used: 8400 KB                              
*  problem: https://codeforces.com/contest/711/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 999999999999
using namespace std;
long n,m,k,color[102],cost[102][102],dp[102][102][102];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     for(long i=0; i<102; i++)
    {
        for(long j=0; j<102; j++)
        {
            for(long b=0; b<102; b++)
            {
                dp[i][j][b]=inf;
            }
        }
    }
     cin>>n>>m>>k;
    for(long i=1; i<=n; i++)cin>>color[i];
     for(long i=1; i<=n; i++)
    {
        for(long j=1; j<=m; j++)
        {
            cin>>cost[i][j];
        }
    }
    if(color[1])dp[1][color[1]][1]=0;
    else
    {
        for(long j=1;j<=m;j++)
        {
            dp[1][j][1]=cost[1][j];
        }
    }
    for(long i=2; i<=n; i++)
    {
        if(color[i])
        {
            long nj=color[i];
            for(long nb=1; nb<=k; nb++)
            {
                dp[i][nj][nb]=dp[i-1][nj][nb];
                for(long jjj=1; jjj<=m; jjj++)
                {
                    if(jjj==nj)continue;
                    dp[i][nj][nb]=min(dp[i][nj][nb],dp[i-1][jjj][nb-1]);
                }
            }
        }
        else
        {
            for(long j=1; j<=m; j++)
            {
                for(long b=1; b<=k; b++)
                {
                    dp[i][j][b]=dp[i-1][j][b]+cost[i][j];
                    for(long jj=1; jj<=m; jj++)
                    {
                        if(jj==j)continue;
                        dp[i][j][b]=min(dp[i][j][b],dp[i-1][jj][b-1]+cost[i][j]);
                    }
                }
            }
        }
    }
    /*for(long i=1;i<=n;i++)
    {
        for(long j=1;j<=m;j++)
        {
            for(long b=1;b<=k;b++)
            {
                cout<<i<<" "<<j<<" "<<b<<" "<<"  ";
                cout<<dp[i][j][b]<<endl;
            }
        }
    }*/
    long ans=inf;
    for(long j=1; j<102; j++)
    {
        ans=min(ans,dp[n][j][k]);
    }
    if(ans>=inf)ans=-1;
    cout<<ans<<endl;
     return 0;
}
 