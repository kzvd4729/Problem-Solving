/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/16/2018 20:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/1006/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,arr[100003];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    if(arr[i]%2==0)arr[i]--;
  }
  for(int i=1;i<=n;i++)
    cout<<arr[i]<<" ";
   return 0;
}