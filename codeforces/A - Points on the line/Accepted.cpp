/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2018 10:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/940/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,d,arr[103];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>d;
    for(long i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+n+1);
    long ans=109;
    for(long i=1;i<=n;i++)
    {
        for(long j=n;j>=1;j--)
        {
            if(arr[j]-arr[i]<=d)
            {
                ans=min(ans,i-1+n-j);
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}