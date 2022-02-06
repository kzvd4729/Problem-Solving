/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/28/2017 09:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/909/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
long n;
cin>>n;
long x=n/2;
long ans=x*(x+1);
if(n&1)ans+=(n/2)+1;
cout<<ans<<endl;
return 0;
}