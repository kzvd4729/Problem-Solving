/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/05/2017 22:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/877/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     long n;
    cin>>n;
    long cnt=0;
    for(long i=2;i<=n;i+=2)
    {
        cnt+=2;
    }
    for(long i=1;i<=n;i+=2)
    {
        cnt++;
    }
    cout<<cnt<<endl;
    for(long i=2;i<=n;i+=2)
    {
        cout<<i<<" ";
    }
    for(long i=1;i<=n;i+=2)
    {
        cout<<i<<" ";
    }
    for(long i=2;i<=n;i+=2)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}