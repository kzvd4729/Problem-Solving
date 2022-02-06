/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/14/2017 10:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/903/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long dp[200],n,x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     dp[0]=1;
    for(long i=0;i<=100;i++)
    {
        if(dp[i])
        {
            dp[i+3]=1;
            dp[i+7]=1;
        }
    }
    cin>>n;
    while(n--)
    {
        cin>>x;
        if(dp[x])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
     return 0;
}