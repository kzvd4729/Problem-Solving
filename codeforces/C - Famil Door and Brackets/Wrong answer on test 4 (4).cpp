/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2017 17:19                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 197900 KB                            
*  problem: https://codeforces.com/contest/629/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,m,cnt,mn=999999,x,i,j,ans,mod=1000000007;
long long int dp[5003][5003];
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
            dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
        }
    }
     for(i=0;i<=x;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j+mn>=0&&j+cnt<=n-m-i)
            {
                ans=(ans+(dp[i][j]%mod)*(dp[x-i][j+cnt]%mod)%mod);
            }
        }
    }
    cout<<ans<<endl;
     return 0;
}