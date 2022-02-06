/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/18/2018 17:48                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/732/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,k,arr[505],ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>arr[i];
  for(int i=2;i<=n;i++)
  {
    if(arr[i]+arr[i-1]>=k)continue;
    ans+=k-arr[i]-arr[i-1];
    arr[i]+=k-arr[i]-arr[i-1];
  }
  cout<<ans<<endl;
  for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
  cout<<endl;
  return 0;
}