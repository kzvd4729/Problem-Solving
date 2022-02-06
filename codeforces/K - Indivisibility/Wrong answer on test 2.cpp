/****************************************************************************************
*  @author: kzvd4729#                                        created: Jan/09/2018 19:26                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/630/problem/K
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n;
int main()
{
cin>>n;
long ans=n/2+n/3+n/5+n/7-n/6-n/10-n/15-n/14-n/21-n/35;
cout<<n-ans<<endl;
return 0;
}