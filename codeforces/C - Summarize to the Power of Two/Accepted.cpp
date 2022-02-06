/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/09/2018 21:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2667 ms                                         memory_used: 156100 KB                            
*  problem: https://codeforces.com/contest/1005/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,pw[33],arr[120002];
map<long,long>mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   for(long i=1;i<=32;i++)
    pw[i]=(1<<i);
  cin>>n;
  for(long i=1;i<=n;i++)
  {
    cin>>arr[i];
    mp[arr[i]]++;
  }
  long ans=0;
  for(long i=1;i<=n;i++)
  {
    mp[arr[i]]--;
    long f=0;
    for(long j=1;j<=32;j++)
      if(mp[pw[j]-arr[i]])f=1;
    if(f==0)ans++;
    mp[arr[i]]++;
  }
  cout<<ans<<endl;
  return 0;
}