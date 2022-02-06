/****************************************************************************************
*  @author: JU_AAA: aniks2645, kzvd4729, prdx9_abir          created: Sep/18/2017 19:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/847/problem/M
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[102],d,n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    d=arr[1]-arr[2];
    long f=0;
    for(long i=1;i<n;i++)
    {
        if(arr[i]-arr[i+1]!=d)
        {
            f=1;
        }
    }
    if(f==0)cout<<arr[n]-d<<endl;
    else cout<<arr[n]<<endl;
     return 0;
}