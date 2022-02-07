/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-10-06 10:17:49                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 40                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10003
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 999999999999
using namespace std;
long dp[55][55],n,cut[55],lf,rg,N;
void mem(void)
{
    for(long i=0;i<54;i++)
    {
        for(long j=0;j<54;j++)
        {
            dp[i][j]=inf;
        }
    }
}
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>N)
    {
        if(N==0)break;
        cin>>n;
        n+=2;
        cut[1]=0;
        for(long i=2;i<n;i++)
        {
            cin>>cut[i];
        }
        cut[n]=N;
        mem();
        for(long i=1;i<n;i++)dp[i][i+1]=0;
        for(long i=2;i<=n;i++)
        {
            for(long j=1;j<=n;j++)
            {
                lf=j;
                rg=j+i;
                if(rg>n)continue;
                for(long k=lf+1;k<rg;k++)
                {
                    dp[lf][rg]=min(dp[lf][rg],cut[rg]-cut[lf]+dp[lf][k]+dp[k][rg]);
                }
            }
        }
        cout<<"The minimum cutting is "<<dp[1][n]<<"."<<endl;

    }
    return 0;
}