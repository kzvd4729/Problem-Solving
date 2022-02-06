/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2019 18:19                        
*  solution_verdict: Time limit exceeded on test 30          language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 77800 KB                             
*  problem: https://codeforces.com/contest/594/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,sq=300;
const long mod=1e9+7;
int vis[N+2],aa[N+2],fr[N+2];
long ans[N+2],inv[N+2];
vector<int>v[N+2];
struct data
{
  int fr,sc,id;
}qr[N+2];
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
void factorise(void)
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      v[j].push_back(i);
      vis[j]=1;
    }
  }
}
bool cmp(data p1,data p2)
{
  int a=p1.fr/sq,b=p2.fr/sq;
  if(a==b)return p1.sc<p2.sc;
  return a<b;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=1;i<=N;i++)inv[i]=bigmod(i,mod-2,mod);
  factorise();int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  int q;cin>>q;
  for(int i=1;i<=q;i++)
  {
    cin>>qr[i].fr>>qr[i].sc;
    qr[i].id=i;
  }
  sort(qr+1,qr+q+1,cmp);
   long nn=1,p1=1,p=1;
  for(int i=qr[1].fr;i<=qr[1].sc;i++)
  {
    nn=(nn*aa[i])%mod;
    for(auto x:v[aa[i]])
    {
      if(!fr[x])p1=(p1*(x-1))%mod,p=(p*x)%mod;
      fr[x]++;
    }
  }
  ans[qr[1].id]=((nn*p1)%mod*bigmod(p,mod-2,mod))%mod;
  for(int ii=2;ii<=q;ii++)
  {
    for(int i=qr[ii-1].sc+1;i<=qr[ii].sc;i++)
    {
      nn=(nn*aa[i])%mod;
      for(auto x:v[aa[i]])
      {
        if(!fr[x])p1=(p1*(x-1))%mod,p=(p*x)%mod;
        fr[x]++;
      }
    }
    for(int i=qr[ii].fr;i<qr[ii-1].fr;i++)
    {
      nn=(nn*aa[i])%mod;
      for(auto x:v[aa[i]])
      {
        if(!fr[x])p1=(p1*(x-1))%mod,p=(p*x)%mod;
        fr[x]++;
      }
    }
    for(int i=qr[ii].sc+1;i<=qr[ii-1].sc;i++)
    {
      nn=(nn*inv[aa[i]])%mod;
      for(auto x:v[aa[i]])
      {
        if(fr[x]==1)p1=(p1*inv[(x-1)])%mod,p=(p*inv[x])%mod;
        fr[x]--;
      }
    }
    for(int i=qr[ii-1].fr;i<qr[ii].fr;i++)
    {
      nn=(nn*inv[aa[i]])%mod;
      for(auto x:v[aa[i]])
      {
        if(fr[x]==1)p1=(p1*inv[(x-1)])%mod,p=(p*inv[x])%mod;
        fr[x]--;
      }
    }
    ans[qr[ii].id]=((nn*p1)%mod*bigmod(p,mod-2,mod))%mod;
  }
  for(int i=1;i<=q;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}