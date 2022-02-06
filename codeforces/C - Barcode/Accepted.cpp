/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/30/2017 10:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/225/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 9999999999999
using namespace std;
long bl[1003],wh[1003],n,m,x,y,dp[1003][3];
char mat[1001][1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m>>x>>y;
    for(long i=1;i<=n;i++)
    {
        for(long j=1;j<=m;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(long i=1;i<=m;i++)
    {
        for(long j=1;j<=n;j++)
        {
            if(mat[j][i]=='.')bl[i]++;
            else wh[i]++;
        }
    }
    for(long i=1;i<=m;i++)
    {
        bl[i]=bl[i-1]+bl[i];
        wh[i]=wh[i-1]+wh[i];
    }
    for(long i=0;i<=1000;i++)dp[i][0]=inf,dp[i][1]=inf;
    dp[0][0]=0,dp[0][1]=0;
    for(long i=0;i<m;i++)
    {
        for(long j=x;j<=y;j++)
        {
            if(i+j>m)continue;
            dp[i+j][0]=min(dp[i+j][0],dp[i][1]+wh[i+j]-wh[i]);
            dp[i+j][1]=min(dp[i+j][1],dp[i][0]+bl[i+j]-bl[i]);
        }
    }
    cout<<min(dp[m][0],dp[m][1])<<endl;
     return 0;
}
 