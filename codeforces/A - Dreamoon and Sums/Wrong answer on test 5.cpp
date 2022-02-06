/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/21/2018 19:25                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/477/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
long a,b,inv;
long bigmod(long b,long p,long mod)
{
 long ret=1;
 while(p)
 { 
  if(p&1)ret=(ret*b)%mod;
  b=(b*b)%mod;p/=2;
 }
 return ret;
}
long sum(long x,long y)
{
 y%=mod;x%=mod;
 long ret=(y*(y+1))%mod;
 ret=(ret*inv)%mod;
 long mn=(x*(x+1))%mod;
 mn=(mn*inv)%mod;
 return (ret+mod-mn)%mod;
}
int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 inv=bigmod(2,mod-2,mod);
 cin>>a>>b;long ans=0;
 for(int i=1;i<b;i++)
 {
  long hw=(i*a-i+1)%mod;
  ans=(ans+hw*i)%mod;
  ans=(ans+(sum(i-1,i*a)*b)%mod)%mod;
 }
 cout<<ans<<endl;
 return 0;
}