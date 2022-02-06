/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/17/2019 22:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 296 ms                                          memory_used: 8000 KB                              
*  problem: https://codeforces.com/contest/1195/problem/D2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
const long mod=998244353;
long aa[N+2],pw[32],fr[22];
long dg(long x)
{
  long ret=0;
  while(x)
  {
    x/=10;ret++;
  }
  return ret; 
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]=1;
  for(long i=1;i<=30;i++)
    pw[i]=(pw[i-1]*10LL)%mod;
   long n;cin>>n;
  for(long i=1;i<=n;i++)cin>>aa[i];
  for(long i=1;i<=n;i++)
    fr[dg(aa[i])]++;
   long ans=0;
  for(long i=1;i<=n;i++)
  {
    long x=aa[i];vector<long>v;
    while(x)
    {
      v.push_back(x%10);
      x/=10;
    }
    long d=dg(aa[i]),qm=0;
    for(long j=0;j<d;j++)
    {
      qm=fr[j];
      if(j==d-1)
      {
        for(long k=d;k<=10;k++)
          qm+=fr[k];
      }
      long p=0;
      for(long k=0;k<j;k++)
      {
        ans=(ans+v[k]*pw[p]*qm)%mod;
        p+=2;
      }
      for(long k=j;k<d;k++)
        ans=(ans+v[k]*pw[p++]*qm)%mod;
    }
    //cout<<ans<<endl;
    //ans=0;///////////
     qm=0;
    for(long j=0;j<d;j++)
    {
      qm=fr[j+1];
      if(j==d-1)
      {
        for(long k=d;k<=10;k++)
          qm+=fr[k+1];
      }
      long p=1;
      for(long k=0;k<j;k++)
      {
        ans=(ans+v[k]*pw[p]*qm)%mod;
        p+=2;
      }
      for(long k=j;k<d;k++)
      {
        //cout<<ans<<" --- "<<p<<" ";
        ans=(ans+v[k]*pw[p++]*qm)%mod;
        //cout<<ans<<endl;
      }
      //cout<<ans<<endl;
      //ans=0;
      //cout<<"break"<<endl;
    }
    //cout<<ans<<endl;
    //return 0;
  }
  cout<<ans<<endl;
  return 0;
}