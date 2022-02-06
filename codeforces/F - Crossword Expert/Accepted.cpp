/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/20/2020 22:33                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 312 ms                                          memory_used: 11500 KB                             
*  problem: https://codeforces.com/contest/1194/problem/F
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
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;
int a[N+2];
const int mod=1e9+7;
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
int r=-1,ret;
int cal(int row,int now)
{
  //cout<<row<<" "<<now<<endl;
  if(r==-1)
  {
    for(int i=0;i<=now;i++)
      ret=(ret+ncr(row,i))%mod;
    r=now;return ret;
  }
  ret=(ret*2)%mod;
  ret=(ret-ncr(row-1,r)+mod)%mod;
   for(int i=r+1;i<=now;i++)
    ret=(ret+ncr(row,i))%mod;
  for(int i=now+1;i<=r;i++)
    ret=(ret-ncr(row,i)+mod)%mod;
  r=now;return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();int n;long t;cin>>n>>t;
  for(int i=1;i<=n;i++)cin>>a[i];
   long inv=(mod+1)/2;long ml=inv;
   //cout<<big(4,mod-2)<<endl;
   long sm=0,ans=0;
  for(int i=1;i<=n;i++)
  {
    sm+=a[i]+1;
    if(sm<=t)ans=(ans+1)%mod;
    else 
    {
      if(i+(t-sm)<0)break;
      ans=(ans+inv*cal(i,i+(t-sm)))%mod;
    }
    inv=(inv*ml)%mod;
  }
  cout<<ans<<endl;
  return 0;
}