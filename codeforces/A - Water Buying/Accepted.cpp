/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/19/2019 20:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1118/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>q;
  while(q--)
  {
    long n,a,b;cin>>n>>a>>b;
    long aa=(a*n);long hl=n/2;
    long bb=hl*b+(n%2)*a;
    cout<<min(aa,bb)<<endl;
  }
  return 0;
}