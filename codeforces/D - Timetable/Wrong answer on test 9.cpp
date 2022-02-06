/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/06/2018 22:33                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/946/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int dp1[517][515],n,m,kk,dp[515][515];
string s[505];
vector<int>v[3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>kk;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=0;i<=500;i++)for(int j=0;j<=500;j++)dp1[i][j]=99999999,dp[i][j]=99999999;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)if(s[i][j]=='1')v[1].push_back(j);
        for(int j=m-1;j>=0;j--)if(s[i][j]=='1')v[2].push_back(j);
        for(int k=0;k<v[1].size();k++)
        {
            for(int j=0;j<=k;j++)
            {
                dp1[i][k]=min(dp1[i][k],v[2][j]-v[1][k-j]+1);
            }
        }
    }
    for(int i=1;i<=n;i++)for(int j=0;j<=m;j++)if(dp1[i][j]==99999999)dp1[i][j]=0;
    for(int i=0;i<=500;i++)dp[1][i]=dp1[1][i];
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=kk;j++)
        {
            for(int k=0;k<=j;k++)
            {
                dp[i][j]=min(dp[i][j],dp1[i][k]+dp[i-1][j-k]);
            }
        }
    }
    cout<<dp[n][kk]<<endl;
    return 0;
}