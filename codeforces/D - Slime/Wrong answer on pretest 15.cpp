/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/06/2018 23:08                        
*  solution_verdict: Wrong answer on pretest 15              language: GNU C++14                               
*  run_time: 186 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1038/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=5e5;
long arr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,ans=0;cin>>n;
  for(long i=1;i<=n;i++)cin>>arr[i],ans+=abs(arr[i]);
  long f=0;
  for(long i=1;i<n;i++)
  {
    if(arr[i]<0&&arr[i+1]>=0)f=1;
    if(arr[i]>=0&&arr[i+1]<0)f=1;
  }
  if(f)cout<<ans<<endl,exit(0);
  for(long i=1;i<=n;i++)arr[i]=abs(arr[i]);
  long tmp=-1e9;
  for(long i=1;i<n;i++)
    tmp=max(tmp,ans-arr[i]-arr[i+1]+abs(arr[i]-arr[i+1]));
  cout<<tmp<<endl;
  return 0;
}