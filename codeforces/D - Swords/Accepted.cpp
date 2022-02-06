/****************************************************************************************
*  @author: * kzvd4729                                       created: Sep/21/2019 13:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1216/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);
  for(int i=1;i<=n;i++)
    aa[i]=aa[n]-aa[i];
  int gc=0;
  for(int i=1;i<=n;i++)
    gc=__gcd(gc,aa[i]);
  long pp=0;
  for(int i=1;i<=n;i++)
    pp+=aa[i]/gc;
  cout<<pp<<" "<<gc<<endl;
   return 0;
}