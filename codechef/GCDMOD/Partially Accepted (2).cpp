/****************************************************************************************
*  @author: kzvd4729                                         created: 03-08-2018 15:29:05                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/AUG18A/problems/GCDMOD
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,a,b;
const long mod=1e9+7;
long bigmod(long b,long p,long mod)
{
  long ret=1;
  b%=mod;
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
    if(df==0)
    {
      cout<<(bigmod(a,n,mod)+bigmod(b,n,mod))%mod<<endl;
      continue;
    }
    long tmp=(bigmod(a,n,df)+bigmod(b,n,df))%df;
    if(tmp==0)
    {
      cout<<df<<endl;
      continue;
    }
    tmp=__gcd(tmp,df);
    cout<<tmp%mod<<endl;
  }
  return 0;
}