/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/03/2018 00:53                        
*  solution_verdict: Time limit exceeded on test 1           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 193100 KB                            
*  problem: https://codeforces.com/contest/566/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1000000;
long dp[1000006],ans,x,n,mx;
vector<long>dv[1000006];
void divisor(void)
{
    for(long i=1;i<=N;i++)
    {
        for(long j=i;j<=N;j+=i)
        {
            dv[j].push_back(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     divisor();
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        mx=0;
        for(auto z:dv[x])mx=max(mx,dp[z]+1);
        dp[x]=mx;
        ans=max(ans,dp[x]);
    }
    ///for(long i=1;i<=24;i++)cout<<i<<" "<<dp[i]<<endl;
    cout<<ans<<endl;
    return 0;
}