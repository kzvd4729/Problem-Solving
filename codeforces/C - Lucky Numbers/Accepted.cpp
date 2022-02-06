/****************************************************************************************
*  @author: kzvd4729#                                        created: Jan/09/2018 18:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/630/problem/C
****************************************************************************************/
#include<bits/stdc++.h> 
#define long long long 
using namespace std; 
long n,ans;
int main()
{
cin>>n;
for(long i=1;i<=n;i++)
{
ans+=pow(2,i);
}
cout<<ans<<endl;
}