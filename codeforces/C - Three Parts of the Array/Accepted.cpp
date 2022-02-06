/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/16/2018 20:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/1006/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
const long inf=1e15;
long arr[N+2],n,s1,s3,id,ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(long i=1;i<=n;i++)
    cin>>arr[i];
  ans=0;
  id=n+1;
  arr[0]=inf;
  for(long i=1;i<=n;i++)
  {
    s1+=arr[i];
    while(s3<s1)s3+=arr[--id];
    if(s1==s3&&i<id)ans=max(ans,s1);
  }
  cout<<ans<<endl;
  return 0;
}