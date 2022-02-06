/****************************************************************************************
*  @author: kzvd4729                                         created: May/16/2019 20:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/341/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long sm=0,tt=0;
  for(int i=1;i<=n;i++)cin>>aa[i],sm+=aa[i]*1LL;
  sort(aa+1,aa+n+1);
   tt=sm;
  for(int i=1;i<=n;i++)
  {
    sm-=((aa[i]-aa[i-1])*1LL)*(n-i+1);
    tt+=sm*2;
  }
  long gc=__gcd(tt,n*1LL);
  cout<<tt/gc<<" "<<n/gc<<endl;
  return 0;
}