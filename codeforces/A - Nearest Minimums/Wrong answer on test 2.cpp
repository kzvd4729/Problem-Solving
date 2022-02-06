/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/29/2017 09:58                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/911/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
long n,arr[200005],mn=99999999999,ans=9999999999,cnt=0;
cin>>n;
for(long i=1;i<=n;i++)cin>>arr[i],mn=min(mn,arr[i]);
for(long i=1;i<=n;i++)
{
if(arr[i]==mn)ans=min(ans,cnt),cnt=0;
else cnt=0;        
}
cout<<++ans<<endl;   
return 0;
}