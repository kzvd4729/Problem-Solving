/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/04/2017 13:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/118/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define M 100000000
using namespace std;
long n1,n2,k1,k2,dp[203][203][3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n1>>n2>>k1>>k2;
     dp[0][0][1]=1;
    dp[0][0][2]=1;
    for(long i=0;i<=n1;i++)
    {
        for(long j=0;j<=n2;j++)
        {
            for(long ii=1;ii<=k1;ii++)dp[i+ii][j][1]=(dp[i][j][2]+dp[i+ii][j][1]+M)%M;
            for(long jj=1;jj<=k2;jj++)dp[i][j+jj][2]=(dp[i][j][1]+dp[i][j+jj][2]+M)%M;
        }
    }
    cout<<(dp[n1][n2][1]+dp[n1][n2][2]+M)%M<<endl;
    return 0;
}
 