/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/28/2018 00:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 436 ms                                          memory_used: 211200 KB                            
*  problem: https://codeforces.com/contest/401/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long k,dp[1<<18][102];
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>s>>k;
    sort(s.begin(),s.end());
    dp[0][0]=1;
    for(long msk=0;msk<(1<<s.size());msk++)
    {
        long pre=-1;
        for(long j=0;s[j];j++)
        {
            long x=s[j]-'0';
            if(pre==x)continue;
            if(!msk&&!x)continue;
            if(msk&(1<<j))continue;
            for(long m=0;m<k;m++)
            {
                if(!dp[msk][m])continue;
                long tmp=(m*10+x)%k;
                dp[msk|(1<<j)][tmp]+=dp[msk][m];
            }
            pre=x;
        }
    }
    cout<<dp[(1<<s.size())-1][0]<<endl;
    return 0;
}