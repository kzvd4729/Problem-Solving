/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-08 18:13:40                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 11 ms                                           memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc109/tasks/abc109_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,x;cin>>n>>x;int gcd=0;
  for(int i=1;i<=n;i++)
  {
    int z;cin>>z;z=abs(z-x);
    gcd=__gcd(gcd,z);
  }
  cout<<gcd<<endl;
  return 0;
}