/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/15/2018 00:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 343 ms                                          memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/313/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
int aa[N+2];long qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1,greater<int>());
   for(int i=1;i<=n;i++)
    qm[i]=qm[i-1]+aa[i]*1LL;
  long pw=1,sum=0;
  while(n)
  {
    sum+=qm[pw];
    n/=4;pw*=4;
  }
  cout<<sum<<endl;
  return 0;
}