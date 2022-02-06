/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/13/2018 20:34                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/735/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,ans;
bool check(long x)
{
    if(((x*(x+1))/2)<=n)return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
     long lo=1,hi=1e9,mid;
     while((hi-lo)>4)
    {
        mid=(lo+hi)/2;
        if(check(mid))lo=mid+1;
        else hi=mid-1;
        ///cout<<mid<<endl;
    }
    for(long i=lo;i<=hi+1;i++)
    {
        if(check(i))ans=i;
    }
    cout<<ans<<endl;
    return 0;
}