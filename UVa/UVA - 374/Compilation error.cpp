/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-18 10:32:52                      
*  solution_verdict: Compilation error                       language: C                                       
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-374
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long bigmod(long b,long p,long m)
{
    long ml=1;
    while(p)
    {
        if(p%2==1)ml=(ml*b)%m;
        b=(b*b)%m;
        p/=2;
    }
    return ml;
}
int main()
{
    long b,p,m;
    while(cin>>b>>p>>m)
    {
        cout<<bigmod(b,p,m)<<endl;
    }
    return 0;
}