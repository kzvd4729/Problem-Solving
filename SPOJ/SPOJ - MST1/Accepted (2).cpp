/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-06 16:12:39                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 100                                        memory_used (MB): 93.2                            
*  problem: https://vjudge.net/problem/SPOJ-MST1
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int dp[20000004],i;
int main()
{
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(i=4; i<=20000000; i++)
    {
        if(i%3==0&&i%2==0)dp[i]=1+min(dp[i-1],(min(dp[i/2],dp[i/3])));
        else if(i%3==0)dp[i]=1+min(dp[i/3],dp[i-1]);
        else if(i%2==0)dp[i]=1+min(dp[i/2],dp[i-1]);
        else dp[i]=1+dp[i-1];
    }
    int t,n;
    cin>>t;
    int tc=0;
    while(t--)
    {
        cin>>n;
        cout<<"Case "<<++tc<<": "<<dp[n]<<endl;
    }
    return 0;
}