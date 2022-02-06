/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2018 18:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 5100 KB                              
*  problem: https://codeforces.com/contest/957/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long n,arr[100005],ans,tmp[100005];
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)cin>>arr[i];
  for(int i=1;i<=n;i++)tmp[i]=max(tmp[i-1],arr[i]+1);
  for(int i=n;i>=1;i--)tmp[i]=max(tmp[i],tmp[i+1]-1);
  for(int i=1;i<=n;i++)ans+=tmp[i]-arr[i]-1;
  cout<<ans<<endl;
  return 0;
}