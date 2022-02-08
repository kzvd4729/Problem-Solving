/****************************************************************************************
*  @author: kzvd4729                                         created: 03-08-2018 15:22:53                      
*  solution_verdict: Run Time Error(SIGFPE)                  language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/AUG18A/problems/GCDMOD
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,a,b;
long bigmod(long b,long p,long mod)
{
  long ret=1;
  while(p)
  {
    if(p&1)ret=(ret*b)%mod;
    b=(b*b)%mod;
    p/=2;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>a>>b>>n;
    long df=abs(a-b);
    long tmp=(bigmod(a,n,df)+bigmod(b,n,df))%df;
    tmp=__gcd(tmp,df);
    cout<<tmp%1000000007<<endl;
  }
  return 0;
}