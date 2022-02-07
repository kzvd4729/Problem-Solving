/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-24 20:09:56                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 9020                                            memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11476
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
/************ Seive **************/
int IsPrime[N+2];vector<int>Prime;
void Seive(int n)
{
  Prime.push_back(2);IsPrime[1]=1;
  for(int i=4;i<=n;i+=2)IsPrime[i]=1;
  int sq=sqrt(n+1);
  for(int i=3;i<=n;i+=2)
  {
    if(IsPrime[i])continue;Prime.push_back(i);
    if(i>sq)continue;
    for(int j=i*i;j<=n;j+=2*i)
      IsPrime[j]=1;
  }
}
///////////////////////////////////

/******************** Pollar-Rho Factorization **************/
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
bool Miller_Test(unsigned long n,int k=5)
{
  if(n<=N)return IsPrime[n];
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
  int t;cin>>t;Seive(N);
  while(t--)
  {
    long n;cin>>n;vector<unsigned long>v;long nn=n;
    for(auto x:Prime)
      while(n%x==0)
        v.push_back(x),n/=x;
    Factorize(n,v);map<long,int>mp;
    for(auto x:v)mp[x]++;
    cout<<nn;int f=0;
    for(auto x:mp)
    {
      if(!f)cout<<" =",f=1;
      else cout<<" *";
      cout<<" ";cout<<x.first;
      if(x.second>1)cout<<"^"<<x.second;
    }
    cout<<"\n";
  }
  return 0;
}