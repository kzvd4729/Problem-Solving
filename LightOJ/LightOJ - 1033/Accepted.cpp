/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-15 18:58:37                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 12                                         memory_used (MB): 1.8                             
*  problem: https://vjudge.net/problem/LightOJ-1033
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long dp[101][101],t,tc;
string s1,s2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>s1;
        s2=s1;
        reverse(s1.begin(),s1.end());
        memset(dp,0,sizeof(dp));
        for(long i=1; i<=s1.size(); i++)
        {
            for(long j=1; j<=s2.size(); j++)
            {
                if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<"Case "<<++tc<<": "<<s1.size()-dp[s1.size()][s2.size()]<<endl;
    }
    return 0;
}