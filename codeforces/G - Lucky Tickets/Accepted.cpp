/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/25/2019 22:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 607 ms                                          memory_used: 8200 KB                              
*  problem: https://codeforces.com/contest/1096/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int mod=998244353;//c*2^k+1 form, 2^k>maximum degree of polynomial
const int g=3;//primitive root or generator
vector<int>r;
void bitReverse(int n)//n is power of 2
{
  r.resize(n);for(int i=0;i<n;i++)r[i]=0;
  int p=0;while((1<<p)<n)p++;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<p;j++)
      if(i&(1<<j))r[i]|=(1<<(p-j-1));
  }
}
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
void dft(vector<int>&a,bool inv)
{
  int n=a.size();
  for(int i=0;i<n;i++)
    if(r[i]<i)swap(a[i],a[r[i]]);
  for(int ln=2;ln<=n;ln*=2)//1 doesn't need to be calculated.
  {
    int m=inv?big(g,mod-1-(mod-1)/ln):big(g,(mod-1)/ln);
    for(int i=0;i<n;i+=ln)//every ln length segment in this level
    {
      int r=1,u,v;
      for(int j=0;j<ln/2;j++)
      {
        u=a[i+j],v=(1LL*r*a[i+j+ln/2])%mod;//even and odd
        a[i+j]=u+v<mod?u+v:u+v-mod;
        a[i+j+ln/2]=u-v>=0?u-v:u-v+mod;
        r=(1LL*r*m)%mod;
      }
    }
  }
  if(inv)
  {
    int ni=big(n,mod-2);
    for(auto &x:a)x=(1LL*x*ni)%mod;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;
  vector<int>a(1<<20);bitReverse(1<<20);
  for(int i=1;i<=k;i++){int x;cin>>x;a[x]=1;}
  dft(a,false);
  for(int i=0;i<(1<<20);i++)
    a[i]=big(a[i],n/2);
  dft(a,true);
  int ans=0;
  for(int i=0;i<(1<<20);i++)
    ans=(1LL*ans+(1LL*a[i]*a[i]))%mod;
  cout<<ans<<endl;
  return 0;
}