/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2018 16:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2200 KB                              
*  problem: https://codeforces.com/contest/939/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[50005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    for(long i=1;i<=n;i++)
    {
        if(arr[arr[arr[i]]]==i)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}