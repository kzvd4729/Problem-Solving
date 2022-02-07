/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-10-05 10:00:03                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10721
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,m,dp[103][103][3];
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n>>k>>m)
    {
        memset(dp,0,sizeof(dp));
        for(long i=1; i<=m; i++)dp[1][i][2]=1;
        for(long i=2; i<=k; i++)
        {
            for(long j=1; j<=n; j++)
            {
                for(long l=1; l<=m; l++)
                {
                    if(i%2==0)dp[i][j+l][1]+=dp[i-1][j][2];
                    else dp[i][j+l][2]+=dp[i-1][j][1];
                }
            }
        }
        if(k%2==0)cout<<dp[k][n][1]<<endl;
        else cout<<dp[k][n][2]<<endl;
    }
    return 0;
}