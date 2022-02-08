/****************************************************************************************
*  @author: kzvd4729                                         created: 22-04-2020 19:54:11                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.77 sec                                        memory_used: 15.8M                                
*  problem: https://www.codechef.com/problems/WGTNKLC
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
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
vector<int>multiply(vector<int>a)
{
  int sz=a.size()*2;
  int n=1;while(n<sz)n<<=1;bitReverse(n);
  a.resize(n);dft(a,false);
  for(int i=0;i<n;i++)a[i]=(1LL*a[i]*a[i])%mod;
  dft(a,true);return a;
}
vector<int>a[17+2];
int cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  a[0].resize(N+1);
  int n,k;cin>>n>>k;
  for(int i=1;i<=k;i++)
  {
    int x;cin>>x;a[0][x]++;
  }
  for(int i=1;i<17;i++)
  {
    a[i]=multiply(a[i-1]);
    while(a[i].size()>N+1)a[i].pop_back();
  }
  for(int i=1;i<=n;i++)
    cnt[__gcd(i,n)]++;
  vector<pair<int,int> >ok;
  for(int i=1;i<=n;i++)
    if(cnt[i])ok.push_back({i,cnt[i]});
  int q;cin>>q;
  while(q--)
  {
    int s,sm=0;cin>>s;
    for(auto x:ok)
    {
      if(s%(n/x.first))continue;
      sm=(sm+1LL*x.second*a[31-__builtin_clz(x.first)][s/(n/x.first)])%mod;
    }
    cout<<(1LL*sm*big(n,mod-2))%mod<<"\n";
  }
  return 0;
}