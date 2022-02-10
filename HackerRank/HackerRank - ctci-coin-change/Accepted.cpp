/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-11 23:13:30                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-ctci-coin-change
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int c[100];
long long int dp[100][1000];
long long int n,co;
long long int fx(long long int s,long long int v)
{
    if(v==0)return 1;
    if(v<0)return 0;
    if(s>=co)return 0;
    if(dp[s][v]!=-1)return dp[s][v];
    return dp[s][v]=fx(s,v-c[s])+fx(s+1,v);
}
int main()
{
    cin>>n>>co;
    for(int i=0;i<co;i++)
    {
        cin>>c[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<fx(0,n)<<endl;
    return 0;
}