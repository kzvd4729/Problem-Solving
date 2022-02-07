/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-08 13:52:00                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 100                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-562
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,arr[101],qm,dp[101][101*501];
long long int fx(long long int s,long long int v)
{
    if(s==n)
    {
        return abs(qm-v-v);
    }
    if(dp[s][v]!=-1)return dp[s][v];
    return dp[s][v]=min(fx(s+1,v+arr[s]),fx(s+1,v));
}
int main()
{
    int t,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        qm=0;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            qm+=arr[i];
        }
        memset(dp,-1,sizeof(dp));
        cout<<fx(0,0)<<endl;
    }
    return 0;
}