/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-17 19:28:49                      
*  solution_verdict: Memory Limit Exceeded                   language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1004
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int grid[210][103];
int dp[210][103][9999];
int n;
void input(void)
{
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            cin>>grid[i][j];
        }
    }
    for(i=n+1;i<2*n;i++)
    {
        for(j=1;j<=2*n-i;j++)
        {
            cin>>grid[i][j];
        }
    }
}
int fx(int i,int j,int v)
{
    if(i==2*n&&j==1)return v;
    if(i>=2*n)return 0;
    if(j>n||j<1)return 0;
    if(dp[i][j][v]!=-1)return dp[i][j][v];
    if(i>=n)
    {
        return dp[i][j][v]=max(fx(i+1,j-1,v+grid[i][j]),fx(i+1,j,v+grid[i][j]));
    }
    else return dp[i][j][v]=max(fx(i+1,j,v+grid[i][j]),fx(i+1,j+1,v+grid[i][j]));
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--)
    {
        memset(grid,0,sizeof(grid));
        input();
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<++tc<<": "<<fx(1,1,0)<<endl;
    }
    return 0;
}