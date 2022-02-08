/****************************************************************************************
*  @author: kzvd4729                                         created: 24-04-2020 18:43:38                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/problems/RNDRATIO
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
const int N=1e5,mod=998244353;
int l[N+2],r[N+2];long pre[N+2];
inline long getSum(int a,int b,int d)
{
  return pre[b/d]-pre[(a-1)/d];
}
long mul[N+2],inv[10*N+2];
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
vector<int>dd[N+2];
void wre52234erw()
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i+i;j<=N;j+=i)
      dd[j].push_back(i);
  }
}
long dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=1;i<=N;i++)pre[i]=pre[i-1]+i;
  inv[1]=1;
  for(int i=2;i<=1000000;i++)
    inv[i]=(mod-((1LL*(mod/i)*inv[mod%i])%mod)+mod)%mod;
  wre52234erw();int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int tt=1;int mx=N;
    for(int i=1;i<=n;i++)
    {
      //cin>>l[i]>>r[i];if(l[i]>r[i])assert(0);
      l[i]=rand()%10+1;
      r[i]=100000-rand()%10;
      mx=min(mx,r[i]);
      tt=(1LL*tt*(r[i]-l[i]+1))%mod;
    }
    for(int i=1;i<=N;i++)mul[i]=big(i,n),dp[i]=1;
    int mm;
    for(int i=1;i<=n;i++)
    {
      for(int g=1;g<1800;g++)
        mul[g]=(1LL*mul[g]*(getSum(l[i],r[i],g)%mod))%mod;
      int ls=1800;
      while(ls<=mx)
      {
        int lo=ls,hi=mx,md;long in=getSum(l[i],r[i],lo);
        while(hi-lo>4)
        {
          md=(lo+hi)/2;
          if(getSum(l[i],r[i],md)==in)lo=md;
          else hi=md;
        }
        for(md=lo;md<=hi;md++)if(getSum(l[i],r[i],md)!=in)break;
        mm=in%mod;
        dp[ls]=(dp[ls]*mm)%mod;
        if(mm>=0&&mm<=1000000)dp[md]=(dp[md]*inv[mm])%mod;
        else dp[md]=(dp[md]*big(mm,mod-2))%mod;
        ls=md;
      }
    }
    dp[0]=1;
    for(int i=1;i<=mx;i++)
    {
      dp[i]=(dp[i]*dp[i-1])%mod;
      mul[i]=(1LL*mul[i]*dp[i])%mod;
    }
    for(int i=mx;i>=1;i--)
    {
      for(auto j:dd[i])
        mul[j]=(mul[j]-mul[i]+mod)%mod;
    }
    //for(int i=1;i<=5;i++)cout<<cnt[i]<<" ** "<<mul[i]<<endl;
    int ex=0;
    for(int i=1;i<=mx;i++)
    {
      int now=(1LL*mul[i]*big(i,mod-2))%mod;
      //now=(1LL*now*cnt[i])%mod;
      ex=(ex+now)%mod;
    }
    ex=(ex+mod)%mod;
    cout<<(1LL*ex*big(tt,mod-2))%mod<<'\n';
  }
  return 0;
}