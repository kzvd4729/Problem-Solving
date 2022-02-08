/****************************************************************************************
*  @author: kzvd4729                                         created: 22-04-2020 21:20:07                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/problems/CUPACO
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int inv,two;
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
long hwierhjkerhh(long x)
{
  x%=mod;long ret=(x*(x+1))%mod;
  ret=(ret*(x+2))%mod;return (ret*inv)%mod;
}
long sum(long a,long b)
{
  b%=mod;a--;a%=mod;
  long r=(b*(b+1))%mod;r=(r*two)%mod;
  long l=(a*(a+1))%mod;l=(l*two)%mod;
  return (r-l+mod)%mod;
}
long erwrfsfwef(long a,long b,long c,long d)
{
  long sm=(sum(c,d)*((a-1)%mod))%mod;
  b-=(a-1);a=1;
  sm=(sm+sum(a,b)*((c-1)%mod))%mod;
  d-=(c-1);c=1;
  return (sm+hwierhjkerhh(b))%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  inv=big(6,mod-2);two=big(2,mod-2);
  int t;cin>>t;
  while(t--)
  {
    long n;cin>>n;
    if(n==1){cout<<1<<endl;continue;}
    if(n==2){cout<<3<<endl;continue;}
    long sm=(n+n-1)%mod;long pw=4,in=3,rv=n-2;
    while(true)
    {
      long qr=pw/4;
      //cout<<in<<" "<<rv<<endl;
      if(in+qr-1<=n)
      {
        sm=(sm+erwrfsfwef(2,2+qr-1,rv-qr+1,rv))%mod;
        in+=qr,rv-=qr;
      }
      else 
      {
        sm=(sm+erwrfsfwef(2,2+rv-1,1,rv))%mod;
        break;
      }
      if(in+qr-1<=n)
      {
        sm=(sm+erwrfsfwef(2+qr-1,2+qr-1+qr-1,rv-qr+1,rv))%mod;
        in+=qr,rv-=qr;
      }
      else 
      {
        sm=(sm+erwrfsfwef(2+qr-1,2+rv-1+qr-1,1,rv))%mod;
        break;
      }
      if(in+qr-1<=n)
      {
        sm=(sm+erwrfsfwef(2,2+qr-1,rv-qr+1,rv))%mod;
        in+=qr,rv-=qr;
      }
      else 
      {
        sm=(sm+erwrfsfwef(2,2+rv-1,1,rv))%mod;
        break;
      }
      if(in+qr-1<=n)
      {
        sm=(sm+erwrfsfwef(2+qr-1,2+qr-1+qr-1,rv-qr+1,rv))%mod;
        in+=qr,rv-=qr;
      }
      else 
      {
        sm=(sm+erwrfsfwef(2+qr-1,2+rv-1+qr-1,1,rv))%mod;
        break;
      }
      pw*=2;
    }
    cout<<(sm+mod)%mod<<"\n";
  }
  return 0;
}