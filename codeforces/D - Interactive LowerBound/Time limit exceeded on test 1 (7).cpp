/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/29/2017 09:53                        
*  solution_verdict: Time limit exceeded on test 1           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/844/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long v,id,n,s,x,vl,nx,q[1002];
int main()
{
    scanf("%lld%lld%lld",&n,&s,&x);
    for(long i=1;i<=1000;i++)
    {
        q[i]=(((i*1000000007)%n)+n+n+7)%n;
    }
    for(long i=1;i<=1000;i++)
    {
        printf("? %lld\n",q[i]);
        fflush(stdout);
        scanf("%lld%lld",&v,&id);
        if(v<=x&&v>vl)
        {
            vl=v;
            nx=id;
        }
     }
    while(true)
    {
        if(nx==-1)break;
        if(vl>=x)break;
        printf("? %lld\n",nx);
        fflush(stdout);
        scanf("%lld%lld",&vl,&nx);
    }
    if(vl>=x)printf("! %lld\n",vl);
    else printf("! -1\n");
    fflush(stdout);
    return 0;
}