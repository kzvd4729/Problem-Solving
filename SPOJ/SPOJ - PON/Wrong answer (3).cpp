/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-24 18:33:32                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-PON
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
/************* Miller Test ***********/
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
bool Miller_Test(long n,int k)
{
  if(n<2)return false;if(n<4)return true;
  if(n%2==0)return false;
  long s=n-1;while(!(s&1))s=(s>>1LL);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  while(k--)
  {
    int f=0;long a=2+(rng()/2)%(n-3);
    long x=bigmod(a,s,n);
    if(x==1||x==n-1)continue;
    while(s!=n-1&&x!=1&&x!=n-1)
      x=(x*x)%n,s=(s<<1LL);
    if(x!=n-1&&!(s&1))return false;
  }
  return true;
}
///////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n;cin>>n;
    if(Miller_Test(n,100))cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}