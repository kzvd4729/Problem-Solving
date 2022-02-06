/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/10/2017 22:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/888/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[1004];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    long ans=0;
    for(long i=2;i<n;i++)if((arr[i]<arr[i-1]&&arr[i]<arr[i+1])||(arr[i]>arr[i-1]&&arr[i]>arr[i+1]))ans++;
    cout<<ans<<endl;
        return 0;
}