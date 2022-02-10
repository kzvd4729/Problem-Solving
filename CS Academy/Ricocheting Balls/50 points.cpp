/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: 50 points                               language: C++                                     
*  run_time: 18 ms                                           memory_used: 772 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,arr[100005],ans,md;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>arr[i];
  sort(arr+1,arr+n+1);
  md=(n+1)/2;
  for(int i=1;i<=n;i++)ans+=abs(arr[md]-arr[i]);
  cout<<ans<<endl;
    return 0;
}