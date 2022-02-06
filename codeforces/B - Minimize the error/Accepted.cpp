/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/07/2018 22:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/960/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k1,k2,arr[1003],brr[1003],crr[1003],sum,k;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k1>>k2;
  for(int i=1;i<=n;i++)cin>>arr[i];
  for(int i=1;i<=n;i++)cin>>brr[i];
  for(int i=1;i<=n;i++)crr[i]=abs(arr[i]-brr[i]);
   k=k1+k2;
   for(int i=1;i<=k;i++)
  {
    long mn=-1e9,id=1;
    for(int j=1;j<=n;j++)
    {
      if(crr[j]>mn)
      {
        mn=crr[j];
        id=j;
      }
    }
    if(mn==0)crr[id]++;
    else crr[id]--;
  }
  for(int i=1;i<=n;i++)sum+=(crr[i]*crr[i]);
  cout<<sum<<endl;
  return 0;
}