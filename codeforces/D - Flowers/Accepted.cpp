/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/28/2017 22:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/474/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define M 1000000007
using namespace std;
long t,k,dp[100004],a,b,qm[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>t>>k;
    dp[0]=1;
    for(long i=1; i<=100000; i++)
    {
        dp[i]=(dp[i-1]+M)%M;
        if(i>=k)dp[i]+=dp[i-k];
        dp[i]=(dp[i]+M)%M;
    }
    for(long i=1; i<=100000; i++)
    {
        qm[i]=(qm[i-1]+dp[i]+M)%M;
    }
    while(t--)
    {
        cin>>a>>b;
        cout<<(qm[b]-qm[a-1]+M)%M<<endl;
    }
     return 0;
}