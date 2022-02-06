/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/17/2018 14:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 60 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/192/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int arr[1003],n,ans=1e9;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>arr[i];
  for(int i=1;i<n;i++)ans=min(ans,max(arr[i],arr[i+1]));
  ans=min(ans,arr[1]);
  ans=min(ans,arr[n]);
  cout<<ans<<endl;
  return 0;
}