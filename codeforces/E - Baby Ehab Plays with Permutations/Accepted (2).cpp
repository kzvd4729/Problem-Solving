/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/21/2021 23:16                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 1170 ms                                         memory_used: 20900 KB                             
*  problem: https://codeforces.com/contest/1516/problem/E
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
const int N=1e6,inf=1e9;
  const int mod=1e9+7;
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
int cal(int k)
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
//index:0 1 2 3 4 5 6  7
//work({1,1,2,3,5,8,13,21});//cal(8)=34,cal(10)=89,cal(100)=782204094
 const int n=900,k=200;
int f[n+2][k+2];
 int solve(int n,int k)
{
  int l=6+(k*4);
  vector<int>v;
  for(int i=2;i<=l;i++)v.push_back(f[i][k]);
   work(v);
  return cal(n-2);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i=0;i<=k;i++)
    f[2][i]=2;
   for(int i=3;i<=n+1;i++)
  {
    f[i][0]=2;
    for(int j=1;j<=k;j++)
      f[i][j]=(f[i-1][j]+1LL*(i-1)*f[i-1][j-1])%mod;
  }
   //cout<<(1LL*f[300][200]*big(2,mod-2))%mod<<endl;
   int nn,kk;cin>>nn>>kk;
  for(int i=1;i<=kk;i++)
    cout<<(1LL*solve(nn,i)*big(2,mod-2))%mod<<'\n';
    return 0;
}