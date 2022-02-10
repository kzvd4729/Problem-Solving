/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-02 19:41:44                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 12                                         memory_used (MB): 1.8                             
*  problem: https://vjudge.net/problem/LightOJ-1017
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,w,k,x,y[102],tc,dp[102][102];
pair<long,long>_search(long id)
{
    long lo,mid,hi;
    lo=1;
    hi=id;
    while(hi-lo>3)
    {
        mid=(lo+hi)/2;
        if(y[id]-y[mid]>w)lo=mid;
        else hi=mid;
    }
    for(long i=lo;i<=hi;i++)if(y[id]-y[i]<=w)return {i,id-i+1};
}
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&w,&k);
        for(long i=1;i<=n;i++)scanf("%lld%lld",&x,&y[i]);
        sort(y+1,y+n+1);
        memset(dp,0,sizeof(dp));
        for(long i=1;i<=n;i++)dp[1][i]=max(dp[1][i-1],_search(i).second);
        for(long i=2;i<=k;i++)
        {
            for(long j=1;j<=n;j++)
            {
                dp[i][j]=max(dp[i][j-1],_search(j).second+dp[i-1][_search(j).first-1]);
            }
        }
        printf("Case %lld: %lld\n",++tc,dp[k][n]);
    }
    return 0;
}