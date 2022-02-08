/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-05-03 13:04:59                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/agc008/tasks/agc008_c
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
#include<queue>
#define long long long
using namespace std;
const long N=1e6,mod=1e9+7;
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(long i=1;i<=7;i++)cin>>aa[i];
  long ans=0;
   ans+=aa[2]*2LL;
  long mn=min({aa[1],aa[4],aa[5]});
  ans+=mn*6LL;aa[1]-=mn;
  ans+=((long)(aa[1]/2))*4LL;
  ans+=((long)(aa[4]/2))*4LL;
  ans+=((long)(aa[5]/2))*4LL;
  cout<<ans/2<<endl;
  return 0;
}