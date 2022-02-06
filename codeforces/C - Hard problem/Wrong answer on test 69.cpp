/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/19/2017 19:19                        
*  solution_verdict: Wrong answer on test 69                 language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 7400 KB                              
*  problem: https://codeforces.com/contest/706/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 9999999999999
using namespace std;
long n,c[100005],dp[100005][2];
string s[100005],r[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long i=0;i<=n;i++)dp[i][0]=inf,dp[i][1]=inf;
    for(long i=1;i<=n;i++)cin>>c[i];
    for(long i=1;i<=n;i++)
    {
        cin>>r[i];
        s[i]=r[i];
        reverse(r[i].begin(),r[i].end());
    }
    s[0]="a";
    r[0]="a";
    dp[0][0]=0;
    dp[0][1]=0;
    for(long i=1;i<=n;i++)
    {
        if(s[i]>=s[i-1]&&s[i]>=r[i-1])
        {
            dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
        }
        else if(s[i]>=s[i-1])
        {
            dp[i][0]=dp[i-1][0];
        }
        else if(s[i]>=r[i-1])
        {
            dp[i][0]=dp[i-1][1];
        }
        if(r[i]>=s[i-1]&&r[i]>=r[i-1])
        {
            dp[i][1]=min(dp[i-1][0],dp[i-1][1])+c[i];
        }
        else if(r[i]>=s[i-1])
        {
            dp[i][1]=dp[i-1][0]+c[i];
        }
        else if(r[i]>=r[i-1])
        {
            dp[i][1]=dp[i-1][1]+c[i];
        }
    }
    long ans=min(dp[n][0],dp[n][1]);
    if(ans>=inf)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}