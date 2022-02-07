/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-07 20:27:04                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 20                                              memory_used:                                      
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
int fx(int pos,int w)
{
    if(pos==n+1)return 0;
    if(dp[pos][w]!=-1)return dp[pos][w];
    dp[pos][w]=fx(pos+1,w);
    if(w-p[pos].w>=0)
    {
        dp[pos][w]=max(dp[pos][w],p[pos].p+fx(pos+1,w-p[pos].w));
    }
    return dp[pos][w];
}
int main()
{
    ///ofstream cout("out.txt");
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>p[i].p;
            cin>>p[i].w;
        }
        p[0].p=0;
        p[0].w=0;
        cin>>g;
        ans=0;
        memset(dp,-1,sizeof(dp));
        for(i=1;i<=g;i++)
        {
            cin>>wt;
            ans+=fx(1,wt);
        }
        cout<<ans<<endl;
    }
    return 0;
}