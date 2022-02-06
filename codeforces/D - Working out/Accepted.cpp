/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/28/2017 12:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 296 ms                                          memory_used: 39300 KB                             
*  problem: https://codeforces.com/contest/430/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 9999999999999999
using namespace std;
long n,m,mat[1002][1002],dp1[1002][1002],dp2[1002][1002],dp3[1002][1002],dp4[1002][1002];
void mem(void)
{
    for(long i=0;i<=1001;i++)
    {
        for(long j=0;j<=1001;j++)
        {
            mat[i][j]=-inf;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mem();
    cin>>n>>m;
    for(long i=1;i<=n;i++)
    {
        for(long j=1;j<=m;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(long i=1;i<=n;i++)
    {
        for(long j=1;j<=m;j++)
        {
            if(i==1&&j==1)dp1[i][j]=mat[i][j];
            else dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+mat[i][j];
        }
    }
    for(long i=n;i>=1;i--)
    {
        for(long j=m;j>=1;j--)
        {
            if(i==n&&j==m)dp2[i][j]=mat[i][j];
            else dp2[i][j]=max(dp2[i+1][j],dp2[i][j+1])+mat[i][j];
        }
    }
    for(long i=n;i>=1;i--)
    {
        for(long j=1;j<=m;j++)
        {
            if(i==n&&j==1)dp3[i][j]=mat[i][j];
            else dp3[i][j]=max(dp3[i+1][j],dp3[i][j-1])+mat[i][j];
        }
    }
    for(long i=1;i<=n;i++)
    {
        for(long j=m;j>=1;j--)
        {
            if(i==1&&j==m)dp4[i][j]=mat[i][j];
            else dp4[i][j]=max(dp4[i-1][j],dp4[i][j+1])+mat[i][j];
        }
    }
    long ans=-inf;
    for(long i=2;i<n;i++)
    {
        for(long j=2;j<m;j++)
        {
            long x1=dp1[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1];
            long x2=dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j];
            ans=max(ans,max(x1,x2));
        }
    }
    cout<<ans<<endl;
    return 0;
}
 