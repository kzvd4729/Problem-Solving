/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-15 23:44:41                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 30                                         memory_used (MB): 18.4                            
*  problem: https://vjudge.net/problem/SPOJ-HOTELS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[300005],n,sum,m,mx,l;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>arr[i];
  arr[n+1]=1e9;
  l=1;
  for(int i=1;i<=n;i++)
  {
    sum+=arr[i];
    while(sum>m)sum-=arr[l++];
    mx=max(mx,sum);
  }
  cout<<mx<<endl;
  return 0;
}