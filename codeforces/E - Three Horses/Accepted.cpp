/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2020 12:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 3900 KB                              
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
int aa[N+2];long ans;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  int gc=0;
  for(int i=1;i<=n;i++)cin>>aa[i],gc=__gcd(gc,aa[i]-1);
  auto add=[&](int x)
  {
    for(int j=0;j<=30;j++)
    {
      if((1LL*x*(1LL<<j))>m)break;
      ans+=m-x*(1<<j);
    }
  };
  int sq=sqrt(gc+1);
  for(int i=1;i<=sq;i++)
  {
    if(gc%i)continue;
    if(i%2)add(i);
    if(gc/i!=i&&(gc/i)%2)add(gc/i);
  }
  cout<<ans<<endl;
  return 0;
}