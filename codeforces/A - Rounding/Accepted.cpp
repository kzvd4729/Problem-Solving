/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/16/2017 22:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/898/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    long l=n%10;
    if(l<=5)cout<<n-l<<endl;
    else cout<<n+10-l<<endl;
     return 0;
}