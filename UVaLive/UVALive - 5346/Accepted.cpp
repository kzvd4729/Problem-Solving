/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-14 19:22:03                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 3                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-5346
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long b,p,m;
long bigmod(long b,long p)
{
    if(p==0)return 1;
    else if(p%2==0)
    {
        long x=(bigmod(b,p/2))%m;
        return (x*x)%m;
    }
    else return (b*bigmod(b,p-1))%m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>b>>p>>m)cout<<(bigmod(b,p))%m<<endl;
    return 0;
}