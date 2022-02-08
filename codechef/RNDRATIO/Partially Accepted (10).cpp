/****************************************************************************************
*  @author: kzvd4729                                         created: 24-04-2020 18:19:28                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 3.34 sec                                        memory_used: 62.8M                                
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
int mul[N+2],inv[100*N+2];
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
  for(int i=2;i<=10000000;i++)
    inv[i]=(mod-1LL*(mod/i)*inv[mod%i]%mod)%mod;
  for(int i=0;i<=1000000;i++)inv[i]=big(i,mod-2);
  wre52234erw();int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int tt=1;
    for(int i=1;i<=n;i++)
    {
      cin>>l[i]>>r[i];
      //l[i]=rand()%10+1;
      //r[i]=100000-rand()%10;
      tt=(1LL*tt*(r[i]-l[i]+1))%mod;
    }
    for(int i=1;i<=N;i++)mul[i]=big(i,n),dp[i]=1;
    int mm;
    for(int i=1;i<=n;i++)
    {
      for(int g=1;g<1800;g++)
        mul[g]=(1LL*mul[g]*(getSum(l[i],r[i],g)%mod))%mod;
      int ls=1800;
      while(ls<=N)
      {
        int lo=ls,hi=N,md;long in=getSum(l[i],r[i],lo);
        while(hi-lo>2)
        {
          md=(lo+hi)/2;
          if(getSum(l[i],r[i],md)==in)lo=md;
          else hi=md;
          //cout<<md<<endl;
        }
        for(md=lo;md<=hi;md++)if(getSum(l[i],r[i],md)!=in)break;
        mm=in%mod;
        dp[ls]=(dp[ls]*mm)%mod;
        if(mm>=0&&mm<=10000000)dp[md]=(dp[md]*inv[mm])%mod;
        else dp[md]=(dp[md]*big(mm,mod-2))%mod;
        ls=md;
      }
    }
    dp[0]=1;
    for(int i=1;i<=N;i++)
    {
      dp[i]=(dp[i]*dp[i-1])%mod;
      mul[i]=(mul[i]*dp[i])%mod;
    }
    for(int i=N;i>=1;i--)
    {
      for(auto j:dd[i])
        mul[j]=(mul[j]-mul[i]+mod)%mod;
    }
    //for(int i=1;i<=5;i++)cout<<cnt[i]<<" ** "<<mul[i]<<endl;
    int ex=0;
    for(int i=1;i<=N;i++)
    {
      int now=(1LL*mul[i]*big(i,mod-2))%mod;
      //now=(1LL*now*cnt[i])%mod;
      ex=(ex+now)%mod;
    }
    cout<<(1LL*ex*big(tt,mod-2))%mod<<'\n';
  }
  return 0;
}