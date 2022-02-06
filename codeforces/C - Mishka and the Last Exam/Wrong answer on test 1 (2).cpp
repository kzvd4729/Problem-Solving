/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/15/2018 20:58                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1093/problem/C
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
  for(long i=n/2+1;i<=n;i++)
    cin>>aa[i];
  aa[n+1]=1e18+1;
  for(long i=1;i<=n/2;i++)
  {
    long j=n-i+1;
    long df=max(aa[j]-aa[j+1],aa[i-1]);
    aa[i]=df;aa[j]-=df;
  }
  for(long i=1;i<=n;i++)
    cout<<aa[i]<<" ";
  cout<<endl;
  return 0;
}