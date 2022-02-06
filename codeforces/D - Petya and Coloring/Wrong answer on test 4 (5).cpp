/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/07/2020 22:25                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/111/problem/D
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
const int N=1e6,mod=1e9+7;
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int fac[N+2];
void init()
{
  fac[0]=1;
  for(int i=1;i<=N;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
}
int ncr(int n,int r)
{
  int ret=(1LL*fac[n]*big(fac[r],mod-2))%mod;
  return (1LL*ret*big(fac[n-r],mod-2))%mod;
}
int color(int n,int k)
{
  int ans=0;
  for(int i=0;i<=k;i++)
  {
    int ml=big(-1,i);ml=(1LL*ml*ncr(k,i));
    ml=(1LL*ml*big(k-i,n));ans=(ans+ml)%mod;
  }
  return ans;
  //return (1LL*ans*big(fac[k],mod-2))%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();int n,m,k;cin>>n>>m>>k;
  int ans=0;
  if(m==1)
  {
    for(int i=1;i<=min(n,k);i++)
      ans=(ans+1LL*color(n,i)*ncr(k,i))%mod;
  }
  else if(m==2)
  {
    for(int i=1;i<=min(n,k);i++)
    {
      int ml=(1LL*color(n,i)*ncr(k,i))%mod;
      ans=(ans+1LL*ml*ml)%mod;
    } 
  }
  else
  {
    for(int i=1;i<=min(n,k);i++)
    {
      int ml=(1LL*color(n,i)*ncr(k,i))%mod;
      for(int j=1;j<=i;j++)
      {
        ml=(1LL*ml*color(n,i))%mod;
        ml=(1LL*ml*ncr(k,i-j))%mod;
        ml=(1LL*ml*ncr(i,j))%mod;
        ml=(1LL*ml*big(n*m-n*2,j))%mod;
        ans=(ans+ml)%mod;
      }
    }
  }
  cout<<(ans+mod)%mod<<endl;
  return 0;
}