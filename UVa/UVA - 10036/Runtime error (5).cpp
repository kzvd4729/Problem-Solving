/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-09 16:48:46                      
*  solution_verdict: Runtime error                           language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10036
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,k,arr[10004];
long long int dp[10004][202];
long long int fx(long long int s,long long int v)
{
    if(s==n)
    {
        if(v%k==0)return 1;
        else return 0;
    }
    if(dp[s][v]!=-1)return dp[s][v];
    return dp[s][v]=(fx(s+1,v+arr[s])%k)|(fx(s+1,v-arr[s])%k);
}
int main()
{
    int t,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=0;i<n;i++)
        {
           cin>>arr[i];
        }
        memset(dp,-1,sizeof(dp));
        if(fx(1,arr[0])==1)cout<<"Divisible"<<endl;
        else cout<<"Not divisible"<<endl;
    }
    return 0;
}