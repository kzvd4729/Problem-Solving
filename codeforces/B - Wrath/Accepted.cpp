/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/17/2017 21:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 311 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/892/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[1000006],n,ans,cnt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    for(long i=n;i>=1;i--)
    {
        if(cnt)cnt--;
        else ans++;
        cnt=max(cnt,arr[i]);
    }
    cout<<ans<<endl;
    return 0;
}
 