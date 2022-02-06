/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/16/2017 23:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/859/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long k,x,mx;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>k;
    for(long i=1;i<=k;i++)
    {
        cin>>x;
        mx=max(mx,x);
    }
    long ans=mx-25;
    if(ans<0)ans=0;
    cout<<ans<<endl;
     return 0;
}