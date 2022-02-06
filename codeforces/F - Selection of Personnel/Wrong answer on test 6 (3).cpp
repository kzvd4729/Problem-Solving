/****************************************************************************************
*  @author: kzvd4729#                                        created: Jan/09/2018 19:19                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/630/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n;
long ncr(long x)
{
long dn=1,nm=1;
for(long i=1;i<=x;i++)dn*=i;
for(long i=n;i>(n-x);i--)nm*=i;
return nm/dn;
}
int main()
{
cin>>n;
cout<<ncr(5)+ncr(6)+ncr(7)<<endl;
return 0;
}