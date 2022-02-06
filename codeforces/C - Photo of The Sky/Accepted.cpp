/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/30/2018 14:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/1013/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e8;
const int N=1e5;
long n,arr[N+N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  n+=n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  sort(arr+1,arr+n+1);
   long hl=n/2;
  long ans=(arr[hl]-arr[1])*(arr[n]-arr[hl+1]);
  for(int i=hl+1;i<n;i++)
    ans=min(ans,(arr[i]-arr[i-hl+1])*(arr[n]-arr[1]));
  cout<<ans<<endl;
  return 0;
}