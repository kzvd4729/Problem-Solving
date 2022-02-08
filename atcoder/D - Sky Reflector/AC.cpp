/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-21 16:58:53                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 46 ms                                           memory_used: 4272 KB                              
*  problem: https://atcoder.jp/contests/arc113/tasks/arc113_d
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=998244353;
 int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
 int row[N+2],col[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m,k;cin>>n>>m>>k;
  if(m>n)swap(n,m);
  if(m==1)
  {
    cout<<big(k,n)<<endl,exit(0);
  }
    for(int i=1;i<=k;i++)row[i]=(big(i,n)-big(i-1,n)+mod)%mod;
  //for(int i=1;i<=k;i++)col[i]=(big(i,m)-col[i-1]+mod)%mod;
    int ans=0;
   for(int i=1;i<=k;i++)
  {
    ans=(ans+1LL*row[i]*big(k-i+1,m))%mod;
  }
  cout<<ans<<endl;
       return 0;
}