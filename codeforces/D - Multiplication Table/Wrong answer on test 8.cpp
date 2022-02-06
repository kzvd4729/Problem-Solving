/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/06/2018 17:31                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 1800 KB                              
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
     while(hi-lo>1)
    {
        md=(lo+hi)/2;
        sum=0;
        for(long i=1;i<=n;i++)sum+=min(m,(md-1)/i);
        if(sum<k)lo=md;
        else hi=md-1;
    }
    cout<<lo<<endl;
    return 0;
}