/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/09/2017 14:30                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/867/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long dp[100004],n;
struct data
{
    long v;
    long d;
}ans[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     dp[0]=1;
    for(long i=1;i<=1000;i++)
    {
        for(long j=0;j<=100000;j++)
        {
            dp[j+i]+=dp[j];
            if(dp[j]>100000)break;
            ans[dp[j]].v=j;
            ans[dp[j]].d=i;
        }
    }
    cin>>n;
    cout<<ans[n].v<<" "<<ans[n].d<<endl;
    for(long i=1;i<=ans[n].d;i++)
    {
        cout<<i<<" ";
    }
    return 0;
}