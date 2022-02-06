/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/16/2018 18:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/149/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[14],k;
bool cmp(long a,long b)
{
    return a>b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>k;
    for(long i=1;i<=12;i++)cin>>arr[i];
    sort(arr+1,arr+13,cmp);
    if(k==0)
    {
        cout<<0<<endl;
        return 0;
    }
    long sum=0;
    for(long i=1;i<=12;i++)
    {
        sum+=arr[i];
        if(sum>=k)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}