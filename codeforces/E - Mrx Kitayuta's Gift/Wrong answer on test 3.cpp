/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/01/2020 03:45                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 167700 KB                            
*  problem: https://codeforces.com/contest/506/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
string ss;long p;
const long mod=10007;
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
  long dp[400+2][200+2][200+2];
long dfs(long i,long a,long b)
{
 long j=p-1-i;
 if(i>j)return a>b;
 if(i==j)
 {
  if(a>b)return 26;if(a==b)return 1;
  return 0;
 }
 if(a>b)return big(26,(p+1)/2-i);
 if(dp[p-i*2][a][b]!=-1)return dp[p-i*2][a][b];
 //if(a==b)return pw((p+1)/2-i-1);
  long now=0;
 if(ss[a]==ss[b])
 {
  now=(now+25*dfs(i+1,a,b))%mod;
  now=(now+dfs(i+1,a+1,b-1))%mod;
 }
 else
 {
  now=(now+24*dfs(i+1,a,b))%mod;
  now=(now+dfs(i+1,a+1,b)+dfs(i+1,a,b-1))%mod;
 }
 return dp[p-i*2][a][b]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int k;cin>>ss>>k;
 p=ss.size()+k;
    vector<int>v;memset(dp,-1,sizeof(dp));
  if(k<=200)cout<<dfs(0,0,ss.size()-1)<<endl,exit(0);
  for(int i=1;i<=200;i++)
  {
   p=ss.size()+i;
   v.push_back(dfs(0,0,ss.size()-1));
  }
  work(v);cout<<calc(k)<<endl;
  return 0;
}