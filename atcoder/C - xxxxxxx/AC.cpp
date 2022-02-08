/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-29 18:08:57                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 10 ms                                           memory_used: 2176 KB                              
*  problem: https://atcoder.jp/contests/arc103/tasks/arc103_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int arr[N+2],mp1[N+2],mp2[N+2],mx1[N+2],mx2[N+2],ans;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>arr[i];
  for(int i=1;i<=n;i+=2)mp1[arr[i]]++;
  for(int i=2;i<=n;i+=2)mp2[arr[i]]++;
   for(int i=1;i<=N;i++)
    mx1[i]=max(mx1[i-1],mp2[i]);
  for(int i=N;i>=1;i--)
    mx2[i]=max(mx2[i+1],mp2[i]);
  for(int i=1;i<=N;i++)
    ans=max(ans,mp1[i]+max(mx1[i-1],mx2[i+1]));
  cout<<n-ans<<endl;
  return 0;
}