/****************************************************************************************
*  @author: kzvd4729                                         created: 14-06-2021 14:06:51                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 34M                                  
*  problem: https://www.codechef.com/problems/RECURRRR
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1000000007,mod=1e9+7;
int big(int b,int p)
{
  int ret=1;
  while(p){if(p&1)ret=(1LL*ret*b)%mod;b=(1LL*b*b)%mod;p/=2;}
  return ret;
}
vector<int>berlekampMassey(vector<int>x)
{
  vector<int>ls,cur;int lf,ld;
  for(int i=0;i<(int)x.size();i++)
  {
    int t=0;
    for(int j=0;j<(int)cur.size();j++)t=(t+1LL*x[i-j-1]*cur[j])%mod;
    if((t-x[i])%mod==0)continue;
     if(!cur.size())
    {
      cur.resize(i+1);lf=i;ld=(t-x[i])%mod;continue;
    }
    int k=-1LL*(x[i]-t)*big(ld,mod-2)%mod;
    vector<int>c(i-lf-1);c.push_back(k);
    for(int j=0;j<ls.size();j++)c.push_back((-1LL*ls[j]*k)%mod);
     if((int)c.size()<(int)cur.size())c.resize((int)cur.size());
    for(int j=0;j<(int)cur.size();j++)
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
int a[N+2],h[N+2],t_[N+2],s[N+2],t[N+2];
void mul(int*p,int*q)
{
  for(int i=0;i<m+m;i++)t_[i]=0;
  for(int i=0;i<m;i++)if(p[i])
    for(int j=0;j<m;++j)
      t_[i+j]=(t_[i+j]+1LL*p[i]*q[j])%mod;
   for(int i=m+m-1;i>=m;i--)if(t_[i])
    for(int j=m-1;~j;j--)
      t_[i-j-1]=(t_[i-j-1]+1LL*t_[i]*h[j])%mod;
  for(int i=0;i<m;++i)p[i]=t_[i];
}
int cal(long k)
{
  for(int i=m;~i;--i)s[i]=t[i]=0;
  s[0]=1;if(m!=1)t[1]=1;else t[0]=h[0];
  while(k)
  {
    if(k&1)mul(s,t);mul(t,t);k>>=1;
  }
  int su=0;
  for(int i=0;i<m;i++)su=(su+1LL*s[i]*a[i])%mod;
  return (su%mod+mod)%mod;
}
void work(vector<int>x)//first element should be non zero
{
  vector<int>v=berlekampMassey(x);m=v.size();
  for(int i=0;i<m;i++)h[i]=v[i],a[i]=x[i];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long a,q;cin>>a>>q;
    vector<int>v;
    v.push_back(1);
    a%=mod;
    for(int i=1;i<=100;i++)
    {
      v.push_back((1LL*a*v.back()+i)%mod);
    }
    // int l=(1LL*a*v.back()+101)%mod;
    // cout<<l<<endl;
    work(v);
    while(q--)
    {
      long x;cin>>x;
      cout<<cal(x)<<'\n';
    }
  }
  return 0;
}