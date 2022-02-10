/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-11 23:18:41                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HDU-2069
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int dp[109][1000];
long long int n,co;
long long int c[]={1,5,10,25,50};
long long int fx(long long int s,long long int v)
{
    if(v==0)return 1;
    if(v<0)return 0;
    if(s>=5)return 0;
    if(dp[s][v]!=-1)return dp[s][v];
    return dp[s][v]=fx(s,v-c[s])+fx(s+1,v);
}
int main()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<fx(0,n)<<endl;
    return 0;
}