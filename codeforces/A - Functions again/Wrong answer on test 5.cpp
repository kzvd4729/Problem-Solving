/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/22/2017 19:48                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/788/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[200005],tmp[200005],n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    for(long i=1;i<n;i++)
    {
        if(i%2==1)tmp[i]=abs(arr[i]-arr[i+1]);
        else tmp[i]=abs(arr[i]-arr[i+1])*(-1);
    }
    long sum=0,mx=0;
    for(long i=1;i<=n;i++)
    {
        sum+=tmp[i];
        mx=max(mx,sum);
        if(sum<0)sum=0;
    }
    cout<<mx<<endl;
      return 0;
}