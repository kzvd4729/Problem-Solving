/****************************************************************************************
*  @author: kzvd4729                                         created: 03-08-2018 16:43:44                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.03 sec                                        memory_used: 15.7M                                
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
  while(p)
  {
    if(p&1)ret=(ret*(b%mod))%mod;
    b=((b%mod)*(b%mod))%mod;
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
    if(df<=mod)
    {
      long tmp=(bigmod(a,n,df)+bigmod(b,n,df))%mod;
      if(tmp==0)cout<<df%mod<<endl;
      else cout<<__gcd(tmp,df)%mod<<endl;
      continue;
    }
    long ans=0;
    for(long i=1;i<=sqrt(df+1);i++)
    {
      if(df%i==0)
      {
        if((a+b)%i==0)
          ans=max(ans,i);
        long j=df/i;
        if(df%j==0&&(a+b)%j==0)
          ans=max(ans,j);
      }
    }
    cout<<ans%mod<<endl;
  }
  return 0;
}