/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/09/2018 08:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/913/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
long n,m;
cin>>n>>m;
if(n>32){cout<<m<<endl;return 0;}
long x=pow(2,n);
cout<<m%x<<endl;
return 0;
}