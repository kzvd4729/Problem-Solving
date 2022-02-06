/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/11/2018 10:36                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/545/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+n+1);
    long now=0,ans=0;
    for(long i=1;i<=n;i++)
    {
       if(now<=arr[i])ans++;
       now+=arr[i];
    }
    cout<<ans<<endl;
    return 0;
}