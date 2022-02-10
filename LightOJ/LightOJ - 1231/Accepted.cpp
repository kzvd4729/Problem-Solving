/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-24 23:34:55                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 260                                        memory_used (MB): 6                               
*  problem: https://vjudge.net/problem/LightOJ-1231
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,tc,coin[100],fr[100],k,n,dp[55][10002];
const long mod=100000007;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(long i=1;i<=n;i++)cin>>coin[i];
        for(long i=1;i<=n;i++)cin>>fr[i];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(long i=1;i<=n;i++)
        {
            for(long j=0;j<=k;j++)dp[i][j]=max(dp[i][j],dp[i-1][j]);
            for(long j=0;j<=k;j++)
            {
                if(dp[i-1][j]==0)continue;
                for(long ii=1;ii<=fr[i];ii++)if(j+coin[i]*ii<=k)dp[i][j+coin[i]*ii]=(dp[i][j+coin[i]*ii]+dp[i-1][j])%mod;
            }
        }
        cout<<"Case "<<++tc<<": "<<dp[n][k]%mod<<endl;
    }
    return 0;
}