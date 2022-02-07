/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-10-05 10:03:12                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10721
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,m,dp[3][53][3];
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
                    if(i%2==0&&j+l<=50)dp[(i+2)%2][j+l][1]+=dp[(i-1+2)%2][j][2];
                    else if(j+l<=50)dp[(i+2)%2][j+l][2]+=dp[(i-1+2)%2][j][1];
                }
            }
        }
        if(k%2==0)cout<<dp[k%2][n][1]<<endl;
        else cout<<dp[k%2][n][2]<<endl;
    }
    return 0;
}