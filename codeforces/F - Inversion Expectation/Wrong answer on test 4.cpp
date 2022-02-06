/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/31/2018 11:24                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1096/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
const long mod=998244353;
long inv[N+2],fac[N+2],bit[N+2],qm[N+2],aa[N+2];
void upd(int x)
{
  for( ;x>0;x-=x&-x)
    bit[x]++;
}
int qry(int x)
{
  int ret=0;
  for( ;x<=N;x+=x&-x)
    ret+=bit[x];
  return ret;
}
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
long seq(long nn,long kk,long fr)
{
  long ls=(fr+((nn-1+mod)%mod)*kk)%mod;
  if(nn%2==0)
  {
    nn/=2;
    return ((fr+ls)*nn)%mod;
  }
  else
  {
    nn/=2;
    long md=(fr+nn*kk)%mod;
    return (((fr+ls)*nn)+md)%mod;
  }
}
void factorial(void)
{
  fac[0]=1;
  for(long i=1;i<=N;i++)
    fac[i]=(fac[i-1]*i)%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  factorial();inv[0]=0;
  for(int i=1;i<=N;i++)
    inv[i]=seq(i,fac[i-1],inv[i-1]);
   int n;cin>>n;int cnt=0;long ans=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;qm[i]=qm[i-1];aa[i]=x;
    if(x==-1)
    {
      qm[i]++;
    }
    else
    {
      ans+=qry(x);upd(x);
    }
  }
  if(!qm[n])cout<<ans<<endl,exit(0);
  ans=(ans+inv[qm[n]])%mod;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]==-1)continue;
    long bg=n-aa[i],sm=aa[i]-1;
    long bp=qm[i-1],sp=qm[n]-qm[i];
     ans=(ans+(((bp*fac[qm[n]-1])%mod)*bg))%mod;
    //cout<<"**"<<ans<<endl;
    ans=(ans+(((sp*fac[qm[n]-1])%mod)*sm))%mod;
    //cout<<"**"<<ans<<endl;
  }
  long dvd=fac[qm[n]];
  //cout<<ans<<" "<<dvd<<endl;
  cout<<(ans*bigmod(dvd,mod-2,mod))%mod<<endl;
  return 0;
}