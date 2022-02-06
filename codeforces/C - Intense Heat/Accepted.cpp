/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/03/2018 21:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1003/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
int n,k,arr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  double ans=0.0;
  while(k<=n)
  {
    int sum=0;
    for(int i=1;i<=k;i++)
      sum+=arr[i];
    double avg=(sum*1.00)/(k*1.00);
    ans=max(ans,avg);
    for(int i=k+1;i<=n;i++)
    {
      sum+=arr[i];
      sum-=arr[i-k];
      avg=(sum*1.00)/(k*1.00);
      ans=max(ans,avg);
    }
    k++;
  }
  cout<<setprecision(10)<<fixed<<ans<<endl;
  return 0;
}