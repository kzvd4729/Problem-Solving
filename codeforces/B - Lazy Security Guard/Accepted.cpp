/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/17/2017 00:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/859/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,y,mn=999999999,m,ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long i=1;i<=n;i++)
    {
        long u=i;
        long v=n/i;
        if(abs(u-v)<mn)
        {
            mn=abs(u-v);
            x=max(u,v);
            y=min(u,v);
        }
     }
    m=n-x*y;
    ans=x*2+y*2;
    if(m)ans+=2;
    cout<<ans<<endl;
    return 0;
}