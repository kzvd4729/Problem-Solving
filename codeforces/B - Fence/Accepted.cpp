/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/04/2017 10:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/363/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[200000],n,k,sum,id,mn;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>k;
    for(long i=1;i<=n;i++)cin>>arr[i];
    for(long i=1;i<=k;i++)sum+=arr[i];
    mn=sum;
    id=1;
    for(long i=k+1;i<=n;i++)
    {
        sum+=arr[i];
        sum-=arr[i-k];
        if(sum<mn)
        {
            mn=sum;
            id=i-k+1;
        }
    }
    cout<<id<<endl;
    return 0;
}
 