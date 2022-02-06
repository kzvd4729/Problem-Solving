/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/06/2020 10:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1326/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)cin>>aa[i];
   for(long i=1;i<=n;i++)
  {
    aa[i]+=aa[i-1];cout<<aa[i]<<" ";
    aa[i]=max(aa[i],aa[i-1]);
  }
  cout<<endl;
  return 0;
}