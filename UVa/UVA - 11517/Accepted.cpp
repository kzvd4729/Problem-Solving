/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-10-05 10:57:45                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 190                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11517
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 9999999999
using namespace std;
long t,total,n,coin[102],dp[102][80002];
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        for(long i=0; i<102; i++)
        {
            for(long j=0; j<80002; j++)
            {
                dp[i][j]=inf;
            }
        }

        cin>>total;
        cin>>n;
        for(long i=1; i<=n; i++)cin>>coin[i];
        dp[0][0]=0;
        for(long i=1; i<=n; i++)
        {
            for(long j=0; j<=10000; j++)
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
                if(dp[i-1][j]!=inf)
                {
                    if(j+coin[i]<=80000)dp[i][j+coin[i]]=min(dp[i][j+coin[i]],dp[i-1][j]+1);
                }
            }
        }
        /*for(long i=0;i<=n;i++)
        {
            for(long j=0;j<=25;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        for(long i=total; ;i++)
        {
            if(dp[n][i]!=inf)
            {
                cout<<i<<" "<<dp[n][i]<<endl;
                break;
            }
        }

    }
    return 0;
}