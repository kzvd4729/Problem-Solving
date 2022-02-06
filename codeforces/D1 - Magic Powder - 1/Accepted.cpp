/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/24/2017 17:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/670/problem/D1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,arr[100005],brr[100005],ans;
bool ok(long x,long kk)
{
    for(long i=1;i<=n;i++)
    {
        if(arr[i]*x>brr[i])kk=kk-(arr[i]*x-brr[i]);
        if(kk<0)return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>k;
    for(long i=1;i<=n;i++)cin>>arr[i];
    for(long i=1;i<=n;i++)cin>>brr[i];
    long lo=0,hi=2000000000,mid;
    while(hi-lo>3)
    {
        mid=lo+(hi-lo)/2;
        if(ok(mid,k))lo=mid+1;
        else hi=mid-1;
        ///cout<<mid<<endl;
    }
    for(long i=max((long)0,lo-1);i<=min((long)2000000000,hi+1);i++)
    {
        ///cout<<ans<<endl;
        if(ok(i,k))ans=i;
        else break;
    }
    cout<<ans<<endl;
    return 0;
}