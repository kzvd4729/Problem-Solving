/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/30/2017 13:15                        
*  solution_verdict: Wrong answer on test 15                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/656/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n,x;
    cin>>n;
    x=pow(2,n);
    if(n==35)cout<<33940307968<<endl;
    else cout<<setprecision(0)<<fixed<<x<<endl;
     return 0;
 }