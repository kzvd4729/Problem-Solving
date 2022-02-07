/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-01 11:07:59                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-374
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long b,p,m;
long bigmod(long b,long p,long mod)
{
    long ret=1;
    while(p)
    {
        if(p%2==1)ret=(ret*b)%mod;
        b=(b*b)%mod;
        p/=2;
    }
    return ret%mod;
}
int main()
{
    while(cin>>b>>p>>m)cout<<bigmod(b,p,m)<<endl;

    return 0;
}