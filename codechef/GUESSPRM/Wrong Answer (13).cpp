/****************************************************************************************
*  @author: kzvd4729                                         created: 14-07-2019 17:14:59                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.31 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/JULY19A/problems/GUESSPRM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
/******************** Pollard-Rho Factorization **************/
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
unsigned long Bigmod(unsigned long b,unsigned long p,unsigned long mod)
{
  unsigned long ret=1;
  while(p)
  {
    if(p%2)ret=Multiply(ret,b,mod);
    b=Multiply(b,b,mod);p/=2;
  }
  return ret;
}
bool Miller_Test(unsigned long n,int k=20)
{
  if(n<2)return false;if(n<4)return true;
  if(n%2==0)return false;
  unsigned long s=n-1;while(s%2==0)s/=2;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  while(k--)
  {
    unsigned long a=2+rng()%(n-2),tmp=s;
    unsigned long md=Bigmod(a,tmp,n);
    if(md==1||md==n-1)continue;
    while(tmp!=n-1&&md!=1&&md!=n-1)
      md=Multiply(md,md,n),tmp*=2;
    if(md!=n-1)return false;
  }
  return true;
}
unsigned long gcd(unsigned long x,unsigned long y) 
{
  if(!x||!y)return x+y;unsigned long t;
  while(x%y)t=x,x=y,y=t%y;
  return y;
}
unsigned long Pollard_Rho(unsigned long n,unsigned long c)
{
  unsigned long x=2,y=2,i=1,k=2,d;
  while(true)
  {
    x=Multiply(x,x,n);
    x=(x+c)%n;d=gcd(x-y,n);
    if(d>1)return d;
    if(++i==k)y=x,k<<=1;
  }
  return n;
}
void Factorize(unsigned long n,vector<unsigned long>&v)
{
  if(n==1)return ;
  if(Miller_Test(n))
  {
    v.push_back(n);return ;
  }
  unsigned long d=n;
  for(int i=2;d==n;i++)
    d=Pollard_Rho(n,i);
  Factorize(d,v);Factorize(n/d,v);
}
//////////////////////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long x1=1000000000-1;
    cout<<1<<" "<<x1<<endl;
    long r1;cin>>r1;
    long nm1=x1*x1-r1;
    long x2=x1+1;
    cout<<1<<" "<<x2<<endl;
    long r2;cin>>r2;
    long nm2=x2*x2-r2;
    unsigned long gc=__gcd(nm1,nm2);
    vector<unsigned long>v;
    Factorize(gc,v);
    sort(v.begin(),v.end());
    cout<<2<<" "<<v.back()<<endl;
    string s;cin>>s;
  }
  return 0;
}