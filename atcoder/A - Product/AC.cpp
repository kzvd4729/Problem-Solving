/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-22 13:09:10                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc086/tasks/abc086_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,c;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>a>>b;
    c=a*b;
    if(c%2==0)cout<<"Even"<<endl;
    else cout<<"Odd"<<endl;
     return 0;
}