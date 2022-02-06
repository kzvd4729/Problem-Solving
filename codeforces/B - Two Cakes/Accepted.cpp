/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/29/2017 10:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/911/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
long n,a,b,pr=0,ans=9999999999;;
cin>>n>>a>>b;
for(long i=1;i<n;i++)
{
long x=i;
long y=n-i;
ans=min(a/x,b/y);
pr=max(pr,ans);
ans=min(b/x,a/y);
pr=max(pr,ans);
}
cout<<pr<<endl;
return 0;
}