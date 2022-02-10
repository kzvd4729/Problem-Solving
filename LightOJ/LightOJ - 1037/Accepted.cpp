/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-28 17:46:33                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 68                                         memory_used (MB): 4.2                             
*  problem: https://vjudge.net/problem/LightOJ-1037
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,mat[20][20],dp[1<<15][20],hl[20],n,upd,ans=16,tc;
char s[20];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)scanf("%d",&hl[i]);
        for(int i=0; i<n; i++)
        {
            scanf("%s",s);
            for(int j=0; j<n; j++)mat[i][j]=s[j]-'0';
        }
        ///for(int i=0; i<n; i++)for(int j=0; j<n; j++)cout<<mat[i][j]<<endl;
        for(int msk=0; msk<(1<<n); msk++)
        {
            for(int i=0; i<=15; i++)dp[msk][i]=1;
            dp[msk][ans]=INT_MAX;
        }
 
        dp[0][ans]=0;
        for(int msk=0; msk<(1<<n); msk++)
        {
            for(int j=0; j<n; j++)
            {
                if(msk&(1<<j))continue;
                upd=msk|(1<<j);
                //cout<<dp[msk][ans]+(hl[j]+dp[msk][j]-1)/dp[msk][j]<<endl;
                dp[upd][ans]=min(dp[upd][ans],dp[msk][ans]+(hl[j]+dp[msk][j]-1)/dp[msk][j]);
                for(long i=0; i<n; i++)dp[upd][i]=max(dp[upd][i],mat[j][i]);
            }
        }
        ///for(int i=0;i<(1<<n);i++)cout<<dp[i][ans]<<endl;
        printf("Case %d: %d\n",++tc,dp[(1<<n)-1][ans]);
    }
    return 0;
}
 