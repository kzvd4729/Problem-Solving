/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-06 14:34:11                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1047
****************************************************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[21][4],x,y,z,t,tc,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            dp[i][1]=x+min(dp[i-1][2],dp[i-1][3]);
            dp[i][2]=y+min(dp[i-1][1],dp[i-1][3]);
            dp[i][3]=z+min(dp[i-1][1],dp[i-1][2]);
        }
        printf("Case %d: %d\n",++tc,min(dp[n][1],min(dp[n][2],dp[n][3])));
    }
    return 0;
}