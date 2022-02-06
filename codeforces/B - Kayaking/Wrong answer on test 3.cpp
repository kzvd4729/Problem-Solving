/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/21/2017 21:26                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/863/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[1002],n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=2*n;i++)cin>>arr[i];
    sort(arr+1,arr+2*n+1);
    long sum=0,mx=0;
    for(long i=1;i<=2*n;i+=2)
    {
        long x=abs(arr[i]-arr[i+1]);
        sum+=x;
        mx=max(x,mx);
    }
    cout<<sum-mx<<endl;
     return 0;
}