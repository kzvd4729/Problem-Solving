/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/21/2017 23:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/900/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,c,x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>a>>b>>c;
     a=a%b;
    long ans=-1;
    for(long i=1;i<=100000;i++)
    {
        a*=10;
        x=a/b;
        if(x==c)
        {
            ans=i;
            break;
        }
        a%=b;
    }
    cout<<ans<<endl;
    return 0;
}