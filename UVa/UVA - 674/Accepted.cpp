/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-11 13:45:31                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 40                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-674
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int c[]={1,5,10,25,50};
int n,dp[5][8000];
int fx(int s,int v)
{
    if(v==0)return 1;
    if(v<0)return 0;
    if(s>4)return 0;
    if(dp[s][v]!=-1)return dp[s][v];
    return dp[s][v]=fx(s,v-c[s])+fx(s+1,v);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    while(cin>>n)
    {
       cout<<fx(0,n)<<endl;
    }
    return 0;
}