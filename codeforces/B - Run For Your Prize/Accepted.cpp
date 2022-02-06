/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/16/2018 22:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/938/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1000000;
long n,arr[100005],ans,now;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    for(long i=1;i<=n;i++)
    {
        now=min(arr[i]-1,N-arr[i]);
        ans=max(ans,now);
    }
    cout<<ans<<endl;
    return 0;
}