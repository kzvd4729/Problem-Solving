/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2018 20:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/932/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string ss,s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>s;
    ss=s;
    reverse(s.begin(),s.end());
    cout<<ss+s<<endl;
     return 0;
}