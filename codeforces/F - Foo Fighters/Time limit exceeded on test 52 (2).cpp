/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2020 20:35                        
*  solution_verdict: Time limit exceeded on test 52          language: GNU C++17                               
*  run_time: 2000 ms                                         memory_used: 8600 KB                              
*  problem: https://codeforces.com/contest/1148/problem/F
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define endl "\n"
#define long long long  
using namespace std;
const long N=3e5;
long a[N+2],b[N+2],n,sm;
bool ck(long msk)
{
  long bl=0;
  for(long i=1;i<=n;i++)
  {
    if((__builtin_popcountll(b[i]&msk))%2==0)bl+=a[i];
    else bl-=a[i];
  }
  if(sm>0)return bl<0;
  return bl>0;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
  for(long i=1;i<=n;i++)cin>>a[i]>>b[i],sm+=a[i];
   long msk=(1LL<<62)-1;//cout<<msk<<endl;
  if(ck(msk))cout<<msk<<endl,exit(0);
  for(long i=0;i<62;i++)
  {
    if(ck(msk^(1LL<<i)))
      cout<<(msk^(1LL<<i))<<endl,exit(0);
  }
  //assert(0);
  for(long i=61;i>=0;i--)
  {
    for(long j=i+1;j<62;j++)
    {
      long now=(msk^(1LL<<i));
      now^=(1LL<<j);
      if(ck(now))cout<<now<<endl,exit(0);
    }
  }
  assert(0);
  return 0;
}