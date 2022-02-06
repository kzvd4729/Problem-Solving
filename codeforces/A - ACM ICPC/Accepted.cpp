/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/14/2017 17:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/890/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     long sum=0,f=0;
    for(long i=1;i<=6;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    long x;
    for(long i=1;i<=6;i++)
    {
        for(long j=i+1;j<=6;j++)
        {
            for(long k=j+1;k<=6;k++)
            {
                x=arr[i]+arr[j]+arr[k];
                if(x==sum-x)f=1;
            }
        }
    }
    if(f)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}