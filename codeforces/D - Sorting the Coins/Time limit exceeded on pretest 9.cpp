/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/16/2017 19:02                        
*  solution_verdict: Time limit exceeded on pretest 9        language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 12100 KB                             
*  problem: https://codeforces.com/contest/876/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[300005],lo,hi,mid,tree[1000000];
void upd(long idx,long val)
{
    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=(idx&-idx);
    }
}
long qry(long idx)
{
    if(idx==0)return 0;
    long sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1; i<=n; i++)cin>>arr[i];
    cout<<1<<" ";
    for(long i=1; i<=n; i++)
    {
        upd(arr[i],1);
        lo=1;
        hi=n;
        while(lo-hi>2)
        {
            mid=(lo+hi)/2;
            long x=qry(n)-qry(mid);
            if(x<n-mid)lo=mid+1;
            else hi=mid-1;
        }
        long ans;
        if(qry(n)==n)
        {
            cout<<1<<" ";
         }
        else {for(long j=max(1LL,lo-1); j<=min(n,hi+1); j++)
        {
            long x=qry(n)-qry(j);
            if(x==n-j)
            {
                ans=x;
                break;
            }
         }
        ///cout<<ans<<endl;
        cout<<i-ans+1<<" ";}
    }
    return 0;
 }