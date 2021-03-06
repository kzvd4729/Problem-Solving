/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/06/2018 17:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/448/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,lo,hi,md,sum,ans,k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n>>m>>k;
     lo=1;
    hi=n*m;
     while(hi-lo>3)
    {
        md=(lo+hi)/2;
        sum=0;
        for(long i=1;i<=n;i++)sum+=min(m,(md-1)/i);
        if(sum<k)lo=md;
        else hi=md;
        ///cout<<md<<" "<<sum<<endl;
    }
    for(long j=lo;j<=hi;j++)
    {
        sum=0;
        for(long i=1;i<=n;i++)sum+=min(m,(j-1)/i);
        if(sum<k)ans=j;
        //cout<<j<<" "<<sum<<endl;
    }
    cout<<ans<<endl;
    return 0;
}