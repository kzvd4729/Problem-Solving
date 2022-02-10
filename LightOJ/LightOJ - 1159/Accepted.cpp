/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-02 16:07:12                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 116                                        memory_used (MB): 3                               
*  problem: https://vjudge.net/problem/LightOJ-1159
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
char s1[60],s2[60],s3[60];
long dp[55][55][55],t,tc;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%s%s%s",&s1,&s2,&s3);
        memset(dp,0,sizeof(dp));
        for(long i=1;i<=strlen(s1);i++)
        {
            for(long j=1;j<=strlen(s2);j++)
            {
                for(long k=1;k<=strlen(s3);k++)
                {
                    if(s1[i-1]==s2[j-1]&&s2[j-1]==s3[k-1])dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                    else dp[i][j][k]=max(max(dp[i][j][k-1],dp[i][j-1][k]),dp[i-1][j][k]);
                }
            }
        }
        printf("Case %lld: %lld\n",++tc,dp[strlen(s1)][strlen(s2)][strlen(s3)]);
    }
    return 0;
}