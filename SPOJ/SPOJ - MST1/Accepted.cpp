/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-06 16:25:05                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 30                                         memory_used (MB): 94.2                            
*  problem: https://vjudge.net/problem/SPOJ-MST1
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int dp[20000004],i;
int fx(int n)
{
    if(dp[n]!=-1)return dp[n];
    if(n==1)dp[n]=0;
    else if(n==2)dp[n]=1;
    else if(n==3)dp[n]=1;
    else if(n%6==0)dp[n]=1+fx(n/3);
    else if(n%3==0)dp[n]=1+min(fx(n/3),fx(n-1));
    else if(n%2==0)dp[n]=1+min(fx(n/2),fx(n-1));
    else dp[n]=1+fx(n-1);
    return dp[n];
}
int main()
{
    int t,nn;
    cin>>t;
    int tc=0;
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        cin>>nn;
        cout<<"Case "<<++tc<<": "<<fx(nn)<<endl;
    }
    return 0;
}