/****************************************************************************************
*  @author: kzvd4729#                                        created: Jan/09/2018 18:04                        
*  solution_verdict: Time limit exceeded on test 6           language: GNU C++14                               
*  run_time: 500 ms                                          memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/630/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
double x=1.000000011,z,ans;
long n;
int main()
{
cin>>z>>n;
for(long i=1;i<=n;i++)
{
z*=x;
}
cout<<setprecision(10)<<fixed<<z<<endl;
return 0;
}