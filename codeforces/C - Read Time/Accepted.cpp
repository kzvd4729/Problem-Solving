/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/15/2018 14:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/343/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long n,m,head[N+10],go[N+10];
bool ok(long tm)
{
    long id=1;
    for(long i=1;i<=n;i++)
    {
        long mn=head[i]-go[id];
        mn=max(0LL,mn);
        if(id>m)return true;
        if(mn>tm)return false;
        while(go[id]<=head[i])
        {
            if(id>m)return true;
            id++;
        }
        while(true)
        {
            if(id>m)return true;
            if((2LL*(go[id]-head[i])+mn<=tm)||(2LL*mn+go[id]-head[i]<=tm))id++;
            else break;
        }
    }
    if(id>m)return true;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(long i=1;i<=n;i++)
        cin>>head[i];
    for(long i=1;i<=m;i++)
        cin>>go[i];
     long lo=0,hi=1e14,md;
    while(hi-lo>3)
    {
        md=(lo+hi)/2;
        if(ok(md))hi=md;
        else lo=md;
    }
    for(md=lo;md<=hi;md++)
        if(ok(md))cout<<md<<endl,exit(0);
    return 0;
}