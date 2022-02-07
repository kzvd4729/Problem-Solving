/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-01 00:33:41                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12470
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;

const long mod=1e9+9;
long big(long b,long p)
{
  long ret=1;
  while(p)
  {
    if(p&1)ret=(1LL*ret*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return ret;
}
vector<int>berlekampMassey(vector<int>x)
{
  vector<int>ls,cur;int lf,ld;
  for(int i=0;i<(int)x.size();i++)
  {
    long t=0;
    for(int j=0;j<(int)cur.size();j++)t=(t+x[i-j-1]*(long)cur[j])%mod;
    if((t-x[i])%mod==0)continue;

    if(!cur.size())
    {
      cur.resize(i+1);lf=i;ld=(t-x[i])%mod;continue;
    }
    long k=-(x[i]-t)*big(ld,mod-2)%mod;
    vector<int>c(i-lf-1);c.push_back(k);
    for(int j=0;j<ls.size();j++)c.push_back(-ls[j]*k%mod);

    if(c.size()<cur.size())c.resize(cur.size());
    for(int j=0;j<cur.size();j++)
      c[j]=(c[j]+cur[j])%mod;

    if(i-lf+(int)ls.size()>=(int)cur.size())
      ls=cur,lf=i,ld=(t-x[i])%mod;
    cur=c;
  }
  for(int i=0;i<cur.size();i++)
    cur[i]=(cur[i]%mod+mod)%mod;
  return cur;
}
int m;
long a[N+2],h[N+2],t_[N+2],s[N+2],t[N+2];
void mul(long*p,long*q)
{
  for(int i=0;i<m+m;i++)t_[i]=0;
  for(int i=0;i<m;i++)if(p[i])
    for(int j=0;j<m;++j)
      t_[i+j]=(t_[i+j]+p[i]*q[j])%mod;

  for(int i=m+m-1;i>=m;i--)if(t_[i])
    for(int j=m-1;~j;j--)
      t_[i-j-1]=(t_[i-j-1]+t_[i]*h[j])%mod;
  for(int i=0;i<m;++i)p[i]=t_[i];
}
long calc(long k)
{
  for(int i=m;~i;--i)s[i]=t[i]=0;
  s[0]=1;if(m!=1)t[1]=1;else t[0]=h[0];
  while(k)
  {
    if(k&1)mul(s,t);mul(t,t);k>>=1;
  }
  long su=0;
  for(int i=0;i<m;i++)su=(su+s[i]*a[i])%mod;
  return (su%mod+mod)%mod;
}
void work(vector<int>x)//first element should be non zero
{
  vector<int>v=berlekampMassey(x);m=v.size();
  for(int i=0;i<m;i++)h[i]=v[i],a[i]=x[i];
}
//cout<<work({1,1,2,3,5,8,13,21},10)<<endl;//89
//cout<<work({1,1,2,3,5,8,13,21},100)<<endl;//782204094
//cout<<work({1,1,2,3,5,8,13,21},10000)<<endl;//24223428

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  work({1,2,3,6,11,20,37});
  long n;while(cin>>n)
  {
   if(n==0)break;
   if(n==1)cout<<0<<"\n";
   else if(n==2)cout<<1<<"\n";
   else if(n==3)cout<<2<<"\n";
   else if(n==4)cout<<3<<"\n";
   else if(n==5)cout<<6<<"\n";
   else if(n==6)cout<<11<<"\n";
   else if(n==7)cout<<20<<"\n";
   else if(n==8)cout<<37<<"\n";
   else cout<<calc(n-2)<<"\n";
   //cout<<endl;
  }

  return 0;
}