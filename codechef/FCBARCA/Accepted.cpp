/****************************************************************************************
*  @author: kzvd4729                                         created: 03-10-2017 21:28:34                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.01 sec                                        memory_used: 15.8M                                
*  problem: https://www.codechef.com/problems/FCBARCA
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define M 1000000007
using namespace std;
long t,n,k,dp[1002][12];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(long i=1;i<=k;i++)dp[1][i]=1;
        for(long i=2;i<=n;i++)
        {
            long sum=0;
            for(long j=0;j<=k;j++)
            {
                sum+=dp[i-1][j];
                sum=(sum+M)%M;
            }
            for(long j=0;j<=k;j++)
            {
                dp[i][j]=sum-dp[i-1][j];
                dp[i][j]=(dp[i][j]+M)%M;
            }
        }
        cout<<(dp[n][0]+M)%M<<endl;
    }
    return 0;
}