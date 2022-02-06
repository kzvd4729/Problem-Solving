/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/18/2018 11:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/964/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
  const long mod=1e9+9;
long n,a,b,k,kk,ukk,uk;
string s,ss;
  long bigmod(long b,long p)
{
if(b==0LL)return 0LL;
long ret=1;
while(p)
{
if(p&1)ret=(ret*b)%mod;
b=(b*b)%mod;
p/=2;
}
return ret%mod;
}
  long unit(long kk)
{
long ret=0,x;
for(int i=0;i<kk;i++)
{
x=(bigmod(a,kk-i-1LL)*bigmod(b,i*1LL))%mod;
if(ss[i]=='-')x*=-1;
x=(x+mod)%mod;
//x=x%mod;
ret=(ret+x)%mod;
}
return ret;
}
       int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
  cin>>n>>a>>b>>k>>s;
kk=k;
ss=s;
++n;
while(kk<n&&kk<100000LL)ss+=s,kk+=k;
  ukk=unit(kk);
uk=unit(k);
  long print=0LL,now=0LL,nn=n,x;
while(true)
{
if(now+kk<=n)
{
x=(bigmod(a,nn-kk)*bigmod(b,now))%mod;
x=(x*ukk)%mod;
print=(print+x)%mod;
nn-=kk;
now+=kk;
if(now==n)break;
}
else
{
x=(bigmod(a,nn-k)*bigmod(b,now))%mod;
x=(x*uk)%mod;
print=(print+x)%mod;
nn-=k;
now+=k;
if(now==n)break;
}
}
  cout<<print<<endl;
  return 0;
}