/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/05/2018 18:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/157/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define pi acos(-1)
using namespace std;
long n;
double lr,sum,arr[102];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+n+1);
    lr=pi*arr[n]*arr[n];
    for(long i=2;i<=n;i+=2)sum+=(pi*arr[i]*arr[i]-pi*arr[i-1]*arr[i-1]);
     cout<<setprecision(10)<<fixed;
    if(n&1)cout<<lr-sum<<endl;
    else cout<<sum<<endl;
     return 0;
}