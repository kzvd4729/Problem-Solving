/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2020 12:39                        
*  solution_verdict: Time limit exceeded on test 14          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/271/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  int gc=0;
  for(int i=1;i<=n;i++)cin>>aa[i],gc=__gcd(gc,aa[i]-1);
   long ans=0;
  for(int i=1;i<=gc;i+=2)
  {
    if(gc%i)continue;
    for(int j=0;j<=30;j++)
    {
      if((1LL*i*(1LL<<j))>m)continue;
      ans+=m-i*(1<<j);
    }
  }
  cout<<ans<<endl;
  return 0;
}