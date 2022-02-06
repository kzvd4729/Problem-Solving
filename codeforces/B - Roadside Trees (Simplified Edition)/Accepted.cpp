/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/16/2018 20:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/265/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,ans,arr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    ans+=abs(arr[i]-arr[i-1]);
  }
  ans+=n+n-1;
  cout<<ans<<endl;
  return 0;
}