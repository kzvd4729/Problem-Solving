/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/24/2017 01:01                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/768/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[100005],n,k,x,mx,mn=9999999999;
int main()
{
    cin>>n>>k>>x;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    sort(arr+1,arr+1+n);
    if(k%2==1)
    {
        for(long i=1;i<=n;i+=2)
        {
            arr[i]=arr[i]^x;
        }
    }
    for(long i=1;i<=n;i++)
    {
        mx=max(mx,arr[i]);
        mn=min(mn,arr[i]);
    }
    cout<<mx<<" "<<mn<<endl;
    return 0;
}