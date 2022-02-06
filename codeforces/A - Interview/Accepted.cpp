/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/24/2017 12:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/631/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long n,x,s1=0,s2=0;
    cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        s1|=x;
    }
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        s2|=x;
    }
    cout<<s1+s2<<endl;
     return 0;
}