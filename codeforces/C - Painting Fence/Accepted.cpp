/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/06/2018 19:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 2300 KB                              
*  problem: https://codeforces.com/contest/448/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[5005];
long segment(long lo,long hi)
{
    ///cout<<lo<<" "<<hi<<endl;
    long mn=1e13;
    for(long i=lo;i<=hi;i++)mn=min(mn,arr[i]);
    for(long i=lo;i<=hi;i++)arr[i]-=mn;
    long l=-1;
    for(long i=lo;i<=hi;i++)
    {
        if(arr[i]&&l==-1)l=i;
        if(!arr[i]&&l!=-1)
        {
            mn+=segment(l,i-1);
            l=-1;
        }
        if(i==hi&&l!=-1)mn+=segment(l,i);
    }
    return min(mn,hi-lo+1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
     cout<<segment(1,n)<<endl;
 //    for(long i=1;i<=n;i++)cout<<arr[i]<<" ";
//    cout<<endl;
     return 0;
}