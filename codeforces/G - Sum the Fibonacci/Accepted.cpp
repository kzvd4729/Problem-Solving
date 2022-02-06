/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/24/2019 14:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1060 ms                                         memory_used: 9400 KB                              
*  problem: https://codeforces.com/contest/914/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int mod=1e9+7;
int aa[N+2],fib[N+2];
 //xor
int big(int b,int p)
{
  int ret=1;
  while(p)
  {
    if(p%2)ret=(1LL*ret*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return ret;
}
void fwhtXor(vector<int>&a,bool inv)
{
  int n=a.size();//sizeof(a) is power of two;
  for(int len=1;2*len<=n;len<<=1)
  {
    for(int i=0;i<n;i+=2*len)
    {
      for(int j=0;j<len;j++)
      {
        int u=a[i+j],v=a[i+j+len];
        a[i+j]=(u+v>=mod?u+v-mod:u+v);
        a[i+j+len]=(u-v<0?u-v+mod:u-v);
      }
    }
  }
  if(inv)
  {
    int inv=big(n,mod-2);
    for(int i=0;i<n;i++)
      a[i]=(1LL*a[i]*inv)%mod;
  }
}
void fwhtAnd(vector<int>&a,bool inv)
{
  int n=a.size();//sizeof(a) is power of two;
  for(int len=1;2*len<=n;len<<=1)
  {
    for(int i=0;i<n;i+=2*len)
    {
      for(int j=0;j<len;j++)
      {
        int u=a[i+j],v=a[i+j+len];
        if(!inv)
        {
          a[i+j]=v;
          a[i+len+j]=(u+v>=mod?u+v-mod:u+v);
        }
        else
        {
          a[i+j]=(v-u<0?v-u+mod:v-u);
          a[i+len+j]=u;
        }
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<int>cnt((1<<17),0);
  for(int i=1;i<=n;i++)
    cin>>aa[i],cnt[aa[i]]++;
  fib[0]=0;fib[1]=1;
  for(int i=2;i<=N;i++)
  {
    fib[i]=fib[i-1]+fib[i-2];
    if(fib[i]>=mod)fib[i]-=mod;
  }
  vector<int>bb((1<<17),0);
  for(int i=0;i<(1<<17);i++)
  {
    for(int j=i; ;j=((j-1)&i))
    {
      bb[i]+=(1LL*cnt[j]*cnt[i^j])%mod;
      if(bb[i]>=mod)bb[i]-=mod;
      if(j==0)break;
    }
  }
  vector<int>dd=cnt;
  fwhtXor(dd,0);
  for(auto &x:dd)x=(1LL*x*x)%mod;
  fwhtXor(dd,1);
  //for(int i=0;i<10;i++)cout<<bb[i]<<" ";cout<<endl;
  for(int i=0;i<bb.size();i++)bb[i]=(1LL*fib[i]*bb[i])%mod;
  for(int i=0;i<cnt.size();i++)cnt[i]=(1LL*fib[i]*cnt[i])%mod;
  for(int i=0;i<dd.size();i++)dd[i]=(1LL*fib[i]*dd[i])%mod;
   //for(int i=0;i<10;i++)cout<<bb[i]<<" ";cout<<endl;
  //for(int i=0;i<10;i++)cout<<cnt[i]<<" ";cout<<endl;
  //for(int i=0;i<10;i++)cout<<dd[i]<<" ";cout<<endl;
   fwhtAnd(bb,0);fwhtAnd(cnt,0);fwhtAnd(dd,0);
  for(int i=0;i<bb.size();i++)
    bb[i]=(1LL*bb[i]*cnt[i]%mod*dd[i])%mod;
  fwhtAnd(bb,1);
  int ans=0;
  for(int i=0;i<17;i++)
    ans=(ans+bb[(1<<i)])%mod;
  cout<<ans<<endl;
   return 0;
}