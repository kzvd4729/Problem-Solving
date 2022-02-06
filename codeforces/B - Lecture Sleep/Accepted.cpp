/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/04/2018 20:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/961/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,k,arr[100005],t[100005],sum,cn,ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>arr[i];
  for(int i=1;i<=n;i++)cin>>t[i];
  for(int i=1;i<=n;i++)if(t[i])sum+=arr[i];
  for(int i=1;i<=n;i++)
  {
    if(t[i]==0)cn+=arr[i];
    if(i>k)if(t[i-k]==0)cn-=arr[i-k];
    ans=max(ans,sum+cn);
  }
  cout<<ans<<endl;
  return 0;
}