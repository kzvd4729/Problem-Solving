/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-11 23:04:36                      
*  solution_verdict: Segmentation Fault                      language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-coinchange
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int c[]={1,2,6,12};
long long int n,dp[6][100005];
long long int mod=1000000007;
long long int fx(long long int s,long long int v)
{
    if(v==0)return 1;
    if(v<0)return 0;
    if(s>3)return 0;
    if(dp[s][v]!=-1)return dp[s][v];
    return dp[s][v]=(fx(s,v-c[s])%mod+fx(s+1,v)%mod)%mod;
}
int main()
{
    int t;
    memset(dp,-1,sizeof(dp));
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<fx(0,n)<<endl;
    }
    return 0;
}