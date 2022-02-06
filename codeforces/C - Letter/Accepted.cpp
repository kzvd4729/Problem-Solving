/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/16/2017 10:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/180/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
long l,dp[100005][2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>s;
    l=s.size();
    for(long i=1;i<=l;i++)
    {
        if(s[i-1]>='A'&&s[i-1]<='Z')dp[i][0]=dp[i-1][0];
        else dp[i][0]=dp[i-1][0]+1;
        if(s[i-1]>='a'&&s[i-1]<='z')dp[i][1]=min(dp[i-1][1],dp[i][0]);
        else dp[i][1]=min(dp[i-1][1]+1,dp[i][0]);
     }
    cout<<dp[l][1]<<endl;
    return 0;
}