/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/26/2017 22:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/895/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[100000],a,b,d;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    long sum=0,mn=999999999999;
    for(long i=1; i<=n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        arr[i+n]=arr[i];
    }
    for(long i=1; i<=n; i++)
    {
        long x=0;
        for(long j=i; j<n+i; j++)
        {
            x+=arr[j];
            a=x;
            b=sum-x;
            d=abs(a-b);
            mn=min(mn,d);
        }
    }
    cout<<mn<<endl;
    return 0;
}
 