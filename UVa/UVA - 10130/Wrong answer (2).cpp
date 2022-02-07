/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-07 19:54:32                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10130
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int dp[1003][33],n,t,i,g,ans,wt;
struct data
{
    int p;
    int w;
}p[1002];
int fx(int pos,int w,int cost)
{
    if(w<0)return 0;
    if(pos==n+1)return cost;
    if(dp[pos][w]!=-1)return dp[pos][w];
    dp[pos][w]=max(fx(pos+1,w-p[pos].w,cost+p[pos].p),fx(pos+1,w,cost));
    return dp[pos][w];
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>p[i].p;
            cin>>p[i].w;
        }
        cin>>g;
        ans=0;
        memset(dp,-1,sizeof(dp));
        for(i=1;i<=g;i++)
        {
            cin>>wt;
            ans+=fx(1,wt,0);
        }
        cout<<ans<<endl;
    }
    return 0;
}