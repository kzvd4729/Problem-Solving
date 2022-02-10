/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-07 23:25:08                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 302                                        memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-5583
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,qm,dp[101][50005],c[101];
ll fx(ll s,ll v)
{
    ll s1,s2;
    if(s==n)
    {
        return abs(qm-v-v);
    }
    if(dp[s][v]!=-1)return dp[s][v];
    s1=fx(s+1,v);
    s2=fx(s+1,v+c[s]);
    dp[s][v]=min(s1,s2);
    return dp[s][v];
}
int main()
{
    ll t,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        qm=0;
        for(i=0;i<n;i++)
        {
            cin>>c[i];
            qm+=c[i];
        }
        memset(dp,-1,sizeof(dp));
        cout<<fx(0,0)<<endl;

    }
    return 0;
}