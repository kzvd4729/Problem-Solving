/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-05-03 13:19:44                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 2 ms                                            memory_used: 2304 KB                              
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
long aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(long i=1;i<=7;i++)cin>>aa[i],bb[i]=aa[i];
  long ans=0;
  ans+=aa[2]*2LL;
  long mn=min({aa[1],aa[4],aa[5]});
  ans+=mn*6LL;aa[1]-=mn,aa[4]-=mn,aa[5]-=mn;
  ans+=((long)(aa[1]/2))*4LL;
  ans+=((long)(aa[4]/2))*4LL;
  ans+=((long)(aa[5]/2))*4LL;
    for(int i=1;i<=7;i++)aa[i]=bb[i];
  long ant=0;
  ant+=aa[2]*2LL;
  ant+=((long)(aa[1]/2))*4LL;aa[1]%=2;
  ant+=((long)(aa[4]/2))*4LL;aa[4]%=2;
  ant+=((long)(aa[5]/2))*4LL;aa[5]%=2;
  mn=min({aa[1],aa[4],aa[5]});
  ant+=mn*6LL;
   for(int i=1;i<=7;i++)aa[i]=bb[i];
  long thr=0;
  thr+=aa[2]*2LL;
  mn=min({aa[1],aa[4],aa[5]});if(mn)mn--;
  thr+=mn*6LL;aa[1]-=mn,aa[4]-=mn,aa[5]-=mn;
  thr+=((long)(aa[1]/2))*4LL;
  thr+=((long)(aa[4]/2))*4LL;
  thr+=((long)(aa[5]/2))*4LL;
   cout<<max({ans,ant,thr})/2<<endl;
   return 0;
}