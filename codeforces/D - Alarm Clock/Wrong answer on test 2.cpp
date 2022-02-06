/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/16/2017 23:25                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 9700 KB                              
*  problem: https://codeforces.com/contest/898/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,k,fre[1000006],x;
int main()
{
    cin>>n>>m>>k;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        fre[x]++;
    }
    for(long i=2;i<=1000000;i++)fre[i]+=fre[i-1];
    long ans=0;
    for(long i=1;i<=1000000;i++)
    {
        x=fre[i+m-1]-fre[i-1];
        ans=max(ans,x-k+1);
    }
    cout<<ans<<endl;
    return 0;
}