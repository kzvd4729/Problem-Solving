/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/04/2017 09:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1496 ms                                         memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/166/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define M 1000000007
using namespace std;
long n,dp[3][5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
     dp[1][2]=1;
    dp[1][3]=1;
    dp[1][4]=1;
    for(long i=2;i<=n;i++)
    {
        long sum=0;
        for(long j=1;j<=4;j++)
        {
           sum+=dp[(i-1+2)%2][j];
           sum=(sum+M)%M;
        }
        for(long j=1;j<=4;j++)
        {
           dp[i%2][j]=sum-dp[(i-1+2)%2][j];
           dp[i%2][j]=(dp[i%2][j]+M)%M;
        }
    }
    cout<<(dp[n%2][1]+M)%M<<endl;
    return 0;
}
 