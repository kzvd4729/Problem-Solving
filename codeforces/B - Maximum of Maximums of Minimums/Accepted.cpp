/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/16/2017 12:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/870/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long n,k,arr[1000000];
    long mx=-99999999999,mn=9999999999;
    cin>>n>>k;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i];
        mx=max(mx,arr[i]);
        mn=min(mn,arr[i]);
    }
    if(k>=3)
    {
        cout<<mx<<endl;
        return 0;
    }
    if(k==1)
    {
        cout<<mn<<endl;
        return 0;
    }
     cout<<max(arr[1],arr[n])<<endl;
     return 0;
}