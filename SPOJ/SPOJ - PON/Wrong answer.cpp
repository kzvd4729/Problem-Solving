/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-24 18:38:42                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-PON
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
/************* Miller Test ***********/
unsigned long bigmod(unsigned long b,unsigned long p,unsigned long mod)
{
  unsigned long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
unsigned long Multiply(unsigned long a,unsigned long b,unsigned long mod)
{
  if(a>b)swap(a,b);unsigned long ret=0;
  while(a)
  {
    if(a%2)ret=(ret+b)%mod;
    b=(b+b)%mod;a/=2;
  }
  return ret;
}
bool Miller_Test(unsigned long n,int k)
{
  if(n<2)return false;if(n<4)return true;
  if(n%2==0)return false;
  unsigned long s=n-1;while(!(s&1))s=(s>>1LL);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  while(k--)
  {
    int f=0;unsigned long a=2+rng()%(n-3);
    unsigned long x=bigmod(a,s,n);
    if(x==1||x==n-1)continue;
    while(s!=n-1&&x!=1&&x!=n-1)
      x=Multiply(x,x,n),s=(s<<1LL);
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