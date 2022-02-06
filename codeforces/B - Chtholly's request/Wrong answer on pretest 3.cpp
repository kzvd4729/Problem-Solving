/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/02/2017 20:19                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
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
     for(long i=1; ;i++)
    {
        x=i;
        z=i;
        if(x%10==0)continue;
        while(x)
        {
            r=x%10;
            x/=10;
            z=z*10+r;
        }
        ///cout<<z<<endl;
        k--;
        sum+=z;
        sum%=p;
        if(k==0)break;
     }
    cout<<sum<<endl;
    return 0;
}
 