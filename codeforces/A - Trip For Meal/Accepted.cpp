/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/16/2017 17:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/876/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,a,b,c;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>a>>b>>c;
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    if(c<a&&c<b)
    {
        cout<<min(a,b)+c*(n-2)<<endl;
    }
    else cout<<min(a,b)*(n-1)<<endl;
     return 0;
}