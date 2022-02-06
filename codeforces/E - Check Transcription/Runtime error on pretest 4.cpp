/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/26/2018 00:51                        
*  solution_verdict: Runtime error on pretest 4              language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 7500 KB                              
*  problem: https://codeforces.com/contest/1056/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long mod=100111001,bs1=31,bs4=17,bs2=37,bs3=39;
long pw1[N+2],pw2[N+2],hs1[N+2],hs2[N+2];
long inv1[N+2],inv2[N+2];
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string b,s;cin>>b>>s;
   pw1[0]=1LL;inv1[0]=bigmod(pw1[0],mod-2,mod);
  for(int i=1;i<=N;i++)
  {
    pw1[i]=(pw1[i-1]*bs1)%mod;
    inv1[i]=bigmod(pw1[i],mod-2,mod);
  }
  pw2[0]=1LL;inv2[0]=bigmod(pw2[0],mod-2,mod);
  for(int i=1;i<=N;i++)
  {
    pw2[i]=(pw2[i-1]*bs2)%mod;
    inv2[i]=bigmod(pw2[i],mod-2,mod);
  }
   int n=s.size();s="0"+s;
   for(int i=1;i<=n;i++)
  {
    hs1[i]=(hs1[i-1]+s[i]*pw1[i])%mod;
    hs2[i]=(hs2[i-1]+s[i]*pw2[i])%mod;
  }
  int zr=0,on=0;
  for(auto x:b)
  {
    if(x=='0')zr++;
    else on++;
  }
  int ans=0;
  for(int i=1;i<n;i++)
  {
    if(i%zr||(n-i)%on)continue;
    int x=i/zr,y=(n-i)/on;
     long zer1=-1,zer2,one1=-1,one2;int pt=1,f=0;
    for(auto xx:b)
    {
      if(xx=='0')
      {
        int lt=pt,rt=pt+x-1;
        long h1=(hs1[rt]-hs1[lt-1]+mod)%mod;
        h1=(h1*inv1[lt-1])%mod;
        long h2=(hs2[rt]-hs2[lt-1]+mod)%mod;
        h2=(h2*inv2[lt-1])%mod;
         if(zer1==-1)
        {
          zer1=h1;zer2=h2;
        }
        else if(zer1!=h1||zer2!=h2)
        {
          f=1;break;
        }
        pt=rt+1;
      }
      else
      {
        int lt=pt,rt=pt+y-1;
        long h1=(hs1[rt]-hs1[lt-1]+mod)%mod;
        h1=(h1*inv1[lt-1])%mod;
        long h2=(hs2[rt]-hs2[lt-1]+mod)%mod;
        h2=(h2*inv2[lt-1])%mod;
         if(one1==-1)
        {
          one1=h1;one2=h2;
        }
        else if(one1!=h1||one2!=h2)
        {
          f=1;break;
        }
        pt=rt+1;
      }
    }
    if(!f&&zer1!=one1&&zer2!=one2)
    {
      ans++;//cout<<x<<" "<<y<<endl;
    }
  }
  cout<<ans<<endl;
  return 0;
}