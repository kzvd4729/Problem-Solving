/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/07/2017 19:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/581/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[100005],mxx[100005],mx,n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    for(long i=n;i>=1;i--)
    {
        mxx[i]=mx;
        mx=max(mx,arr[i]);
    }
    for(long i=1;i<=n;i++)
    {
        if(mxx[i]-arr[i]+1<0)cout<<0<<" ";
        else cout<<mxx[i]-arr[i]+1<<" ";
    }
     return 0;
}
 