/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/10/2018 20:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 5100 KB                              
*  problem: https://codeforces.com/contest/962/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long x,arr[200005],sum,n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>arr[i],sum+=arr[i];
   for(int i=1;i<=n;i++)
  {
    x+=arr[i];
    if(x>=(sum+1)/2)cout<<i<<endl,exit(0);
  }
  return 0;
}