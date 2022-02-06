/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2017 17:15                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 99800 KB                             
*  problem: https://codeforces.com/contest/629/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,mn=999999,x,i,j,ans;
int dp[5003][5003];
string s;
int main()
{
    cin>>n>>m;
    cin>>s;
    for(char c:s)
    {
        c=='('?cnt++:cnt--;
        mn=min(cnt,mn);
    }
    x=n-m;
    dp[0][0]=1;
    for(i=1;i<=x;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j>0)dp[i][j]=dp[i-1][j-1];
            dp[i][j]=(dp[i][j]+dp[i-1][j+1])%(int)1e9+7;
        }
    }
     for(i=0;i<=x;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j+mn>=0&&j+cnt<=n-m-i)
            {
                ans=(ans+dp[i][j]%(int)1e9+7*dp[x-i][j+cnt]%(int)1e9+7)%(int)1e9+7;
            }
        }
    }
    cout<<ans<<endl;
     return 0;
}