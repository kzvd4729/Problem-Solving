/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/27/2020 19:49                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 140 ms                                          memory_used: 5200 KB                              
*  problem: https://codeforces.com/contest/1265/problem/E
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
#define long long long  
using namespace std;
const int N=2e5,mod=998244353;
int a[N+2],s[N+2];
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   s[0]=1;
  for(int i=1;i<=n;i++)
  {
    int p=(1LL*a[i]*big(100,mod-2))%mod;
    s[i]=(1LL*s[i-1]*p)%mod;
  }
  int inv=s[n];int ad=0;
  for(int i=0;i<n;i++)ad=(ad+s[i])%mod;
   cout<<(1LL*ad*big(inv,mod-2))%mod<<endl;
    return 0;
}