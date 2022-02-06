/****************************************************************************************
*  @author: kzvd4729#                                        created: Jan/09/2018 18:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/630/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,ans;
int main()
{
cin>>n;
x=n*6;
ans=(x/2)*(n+1);
cout<<ans+1<<endl;
return 0;
}