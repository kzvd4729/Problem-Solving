/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/26/2017 17:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 312 ms                                          memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/706/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[100005],n,x,q,ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    arr[0]=0;
    arr[n+1]=999999999999;
     cin>>q;
    while(q--)
    {
        cin>>x;
         long lo=0,hi=n+1,mid;
        while(hi-lo>=3)
        {
            long mid=(lo+hi)/2;
            if(arr[mid]>x)
            {
                hi=mid-1;
            }
            else lo=mid+1;
        }
        for(long i=max(0LL,lo-1);i<=min(n,hi+1);i++)
        {
            if(arr[i]<=x)ans=i;
        }
        cout<<ans<<endl;
    }
    return 0;
}