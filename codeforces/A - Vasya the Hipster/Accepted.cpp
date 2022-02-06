/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/07/2017 19:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/581/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>a>>b;
    if(a>b)swap(a,b);
     cout<<a<<" "<<(b-a)/2<<endl;
     return 0;
}
 