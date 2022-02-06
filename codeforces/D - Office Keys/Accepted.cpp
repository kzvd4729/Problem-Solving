/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/15/2017 14:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 33400 KB                             
*  problem: https://codeforces.com/contest/831/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long int
#define inf 9999999999;
using namespace std;
long n,k,p,nn[1003],kk[2003],i,ans,dp[2002][2002];
long fx(long mp,long kp)
{
    if(mp>n)return 0;
    if(kp>k)return inf;
    if(dp[mp][kp]!=-1)return dp[mp][kp];
    long dis=abs(nn[mp]-kk[kp])+abs(kk[kp]-p);
    dp[mp][kp]=max(dis,fx(mp+1,kp+1));
    dp[mp][kp]=min(dp[mp][kp],fx(mp,kp+1));
    return dp[mp][kp];
}
int main()
{
    cin>>n>>k>>p;
    for(i=1;i<=n;i++)cin>>nn[i];
    for(i=1;i<=k;i++)cin>>kk[i];
    sort(nn+1,nn+n+1);sort(kk+1,kk+k+1);
    memset(dp,-1,sizeof(dp));
    fx(1,1);
    cout<<dp[1][1]<<endl;
    return 0;
}