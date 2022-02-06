/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2018 11:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/940/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long x,k,a,b,ans,ex,rm,xx;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>x>>k>>a>>b;
    if(k==1)
    {
        cout<<(x-1)*a<<endl;
        return 0;
    }
    while(true)
    {
        if(x%k)
        {
            if(x<k)break;
            rm=x%k;
            x-=rm;
            ans+=rm*a;
        }
        else
        {
            if(x<k)break;
            xx=x/k;
            rm=x-xx;
            if(a*rm>b)
            {
                x=xx;
                ans+=b;
            }
            else break;
        }
    }
    ans+=(x-1)*a;
    cout<<ans<<endl;
    return 0;
}