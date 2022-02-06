/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/25/2020 18:57                        
*  solution_verdict: Time limit exceeded on test 5           language: GNU C++17 (64)                          
*  run_time: 2500 ms                                         memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1305/problem/F
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
const int N=1e6;
long Multiply(long a,long b,long mod)
{
  __int128 aa=a,bb=b;
  return (a*b)%mod;
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool Miller_Test(long n,int k=5)
{
  if(n<2)return false;if(n<4)return true;
  if(n%2==0)return false;
  long s=n-1;while(s%2==0)s/=2;
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
map<long,int>mp;vector<pair<long,int> >a;
long ans=1e18;
void upd(long x)
{
  long now=0;
  for(int i=0;i<a.size();i++)
  {
    if(a[i].first<=x)now+=(x-a[i].first)*a[i].second;
    else now+=min(a[i].first%x,x-a[i].first%x)*a[i].second;
    if(now>=ans)return;
  }
  //cout<<now<<" "<<x<<endl;
  ans=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  vector<long>v;int n;cin>>n;vector<long>p;p.push_back(2);
  for(int i=1;i<=n;i++)
  {
    long x;cin>>x;mp[x]++;if(mp[x]>1)continue;
    v.clear();Factorize(x,v);
    for(auto z:v)p.push_back(z);
  }
  sort(p.begin(),p.end());
  p.erase(unique(p.begin(),p.end()),p.end());
   for(auto x:mp)a.push_back(x);
  shuffle(a.begin(),a.end(),rng);
   for(auto x:p)upd(x);cout<<ans<<endl;
   //for(int i=0;i<a.size();i++)
    //cout<<a[i].first<<" "<<a[i].second<<endl;
     return 0;
}