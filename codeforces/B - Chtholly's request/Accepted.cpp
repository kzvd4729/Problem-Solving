/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/02/2017 20:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/897/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long k,p,x,z,sum,r;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>k>>p;
    for(long i=1;i<=k;i++)
    {
        x=i;
        z=i;
        while(x)
        {
            r=x%10;
            x/=10;
            z=z*10+r;
        }
        sum=(sum+z)%p;
    }
    cout<<sum%p<<endl;
    return 0;
}
 