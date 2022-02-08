/****************************************************************************************
*  @author: kzvd4729                                         created: 24-04-2020 15:45:25                      
*  solution_verdict: Time Limit Exceeded                     language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/problems/RNDRATIO
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,mod=998244353;
int l[N+2],r[N+2];
int getSum(int a,int d)
{
  int i=a/d;
  int sm=((1LL*i*(i+1))/2)%mod;
  return (1LL*sm*d)%mod;
}
int getSum(int a,int b,int d)
{
  return (getSum(b,d)-getSum(a-1,d)+mod)%mod;
}
int mul[N+2];
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int tt=1;
    for(int i=1;i<=n;i++)cin>>l[i]>>r[i],tt=(1LL*tt*(r[i]-l[i]+1))%mod;
    for(int i=1;i<=N;i++)mul[i]=1;
    for(int i=1;i<=n;i++)
    {
      for(int g=1;g<=100000;g++)
      {
        mul[g]=(1LL*mul[g]*getSum(l[i],r[i],g))%mod;
      }
    }
    for(int i=100000;i>=1;i--)
    {
      for(int j=1;j<i;j++)
      {
        if(i%j==0)
          mul[j]=(mul[j]-mul[i]+mod)%mod;
      }
    }
    //for(int i=1;i<=5;i++)cout<<cnt[i]<<" ** "<<mul[i]<<endl;
    int ex=0;
    for(int i=1;i<=100000;i++)
    {
      int now=(1LL*mul[i]*big(i,mod-2))%mod;
      //now=(1LL*now*cnt[i])%mod;
      ex=(ex+now)%mod;
    }
    cout<<(1LL*ex*big(tt,mod-2))%mod<<endl;
  }
  return 0;
}