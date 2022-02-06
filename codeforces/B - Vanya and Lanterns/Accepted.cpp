/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/01/2017 12:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/492/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,l,arr[1005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>l;
    for(long i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+n+1);
    double ans=max(arr[1]-0,l-arr[n]);
    for(long i=2;i<=n;i++)
    {
        double dis=arr[i]-arr[i-1];
        ans=max(ans,dis/2);
    }
    cout<<setprecision(12)<<fixed<<ans<<endl;
     return 0;
}
 