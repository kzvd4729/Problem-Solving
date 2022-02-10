/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-16 20:05:08                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 581                                        memory_used (MB): 17.7                            
*  problem: https://vjudge.net/problem/LightOJ-1236
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long fr[N+2],cal[N+2];
/******************** Pollard-Rho Factorization **************/
long Multiply(long a,long b,long mod)
{
  if(a>b)swap(a,b);long ret=0;
  while(a)
  {
    if(a%2)ret=(ret+b)%mod;
    b=(b+b)%mod;a/=2;
  }
  return ret;
}
long Bigmod(long b,long p,long mod)
{
  long ret=1;
  while(p)
  {
    if(p%2)ret=Multiply(ret,b,mod);
    b=Multiply(b,b,mod);p/=2;
  }
  return ret;
}
bool Miller_Test(long n,int k=20)
{
  if(n<2)return false;if(n<4)return true;
  if(n%2==0)return false;
  long s=n-1;while(s%2==0)s/=2;
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  while(k--)
  {
    long a=2+rand()%(n-2),tmp=s;
    long md=Bigmod(a,tmp,n);
    if(md==1||md==n-1)continue;
    while(tmp!=n-1&&md!=1&&md!=n-1)
      md=Multiply(md,md,n),tmp*=2;
    if(md!=n-1)return false;
  }
  return true;
}
long gcd(long x,long y)
{
  if(!x||!y)return x+y;long t;
  while(x%y)t=x,x=y,y=t%y;
  return y;
}
long Pollard_Rho(long n,long c)
{
  long x=2,y=2,i=1,k=2,d;
  while(true)
  {
    x=Multiply(x,x,n);
    x=(x+c)%n;d=gcd(abs(x-y),n);
    //cout<<d<<endl;getchar();
    if(d>1)return d;
    if(++i==k)y=x,k<<=1;
  }
  return n;
}
void Factorize(long n,vector<long>&v)
{
  if(n==1)return ;
  if(Miller_Test(n))
  {
    v.push_back(n);return ;
  }
  long d=n;
  for(long i=2;d==n;i++)
    d=Pollard_Rho(n,i);
  Factorize(d,v);Factorize(n/d,v);
}
//////////////////////////////////////////////////////////
int main()
{
  //freopen("inp.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    long n;cin>>n;vector<long>v;
    Factorize(n,v);map<long,int>mp;
    for(int i=0;i<v.size();i++)mp[v[i]]++;
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<v.size();i++)
      fr[i]=mp[v[i]];
    int x=v.size();
    for(int msk=0;msk<(1<<x);msk++)
    {
      long ml=1;
      for(int i=0;i<x;i++)
        if(!(msk&(1<<i)))ml*=fr[i];
      cal[msk]=ml;
      //cout<<msk<<" "<<cal[msk]<<endl;
    }
    int gl=(1<<x)-1;
    long ans=0,sm=cal[gl];
    for(int i=0;i<(1<<x)-1;i++)
    {
      for(int j=0;j<(1<<x)-1;j++)
        if((i|j)==gl)ans+=cal[i]*cal[j];
      sm+=cal[i];
    }
    cout<<"Case "<<++tc<<": "<<ans/2+sm<<"\n";
  }
  return 0;
}