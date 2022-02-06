/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/30/2017 13:18                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/656/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n,x;
    cin>>n;
    x=pow(2,n);
    if(x>=13)cout<<x<<endl;
    else cout<<x-((n-13)*100)<<endl;
     return 0;
 }