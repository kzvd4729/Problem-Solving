/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/07/2018 02:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 156 ms                                          memory_used: 9500 KB                              
*  problem: https://codeforces.com/contest/946/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e12;
long pd[505][505],n,m,kk,dp[505][505];
string s[505];
vector<long>v[505][3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
      cin>>n>>m>>kk;
     for(long i=1;i<=n;i++)cin>>s[i];
    for(long i=0;i<=500;i++)
    {
        for(long j=0;j<=500;j++)pd[i][j]=inf,dp[i][j]=inf;
    }
    for(long i=1;i<=n;i++)
    {
        for(long j=0;j<m;j++)if(s[i][j]=='1')v[i][1].push_back(j);
        for(long j=m-1;j>=0;j--)if(s[i][j]=='1')v[i][2].push_back(j);
        for(long k=0;k<v[i][1].size();k++)
        {
            for(long j=0;j<=k;j++)
            {
                pd[i][k]=min(pd[i][k],v[i][2][j]-v[i][1][k-j]+1);
            }
        }
    }
    for(long i=1;i<=n;i++)
    {
        for(long j=0;j<=m;j++)if(pd[i][j]==inf)pd[i][j]=0;
    }
     for(long i=0;i<=500;i++)dp[1][i]=pd[1][i];
     for(long i=2;i<=n;i++)
    {
        for(long j=0;j<=kk;j++)
        {
            for(long k=0;k<=j;k++)
            {
                dp[i][j]=min(dp[i][j],pd[i][k]+dp[i-1][j-k]);
            }
        }
    }
    for(long i=1;i<=n;i++)
    {
        for(long j=0;j<=kk;j++)if(dp[i][j]==inf)dp[i][j]=0;
    }
    cout<<dp[n][kk]<<endl;
 //    for(long i=1;i<=n;i++)
//    {
//        for(long j=0;j<=m;j++)cout<<pd[i][j]<<" ";
//        cout<<endl;
//    }
    return 0;
}