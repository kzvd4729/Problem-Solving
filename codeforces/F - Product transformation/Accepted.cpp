/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/05/2019 19:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 967 ms                                          memory_used: 13000 KB                             
*  problem: https://codeforces.com/contest/852/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6+123,inf=1e9;
 int isPrime[N+2];vector<int>prime;
void seive(int n)
{
  prime.push_back(2);isPrime[1]=1;
  for(int i=4;i<=n;i+=2)isPrime[i]=1;
  int sq=sqrt(n+1);
  for(int i=3;i<=n;i+=2)
  {
    if(isPrime[i])continue;prime.push_back(i);
    if(i>sq)continue;
    for(int j=i*i;j<=n;j+=2*i)
      isPrime[j]=1;
  }
}
int big(int b,int p,int m)
{
  int ret=1;
  while(p){if(p&1)ret=(1LL*ret*b)%m;b=(1LL*b*b)%m;p/=2;}
  return ret;
}
int fac[N+2];
void init(int n,int mod)
{
  fac[0]=1;
  for(int i=1;i<=n;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
}
int ncr(int n,int r,int mod)
{
  int a=fac[n];a=(1LL*a*big(fac[r],mod-2,mod))%mod;
  return (1LL*a*big(fac[n-r],mod-2,mod))%mod;
}
int ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive(N);
  int n,m,a,q,p;cin>>n>>m>>a>>q;
  for(auto x:prime)
    if(big(a,x,q)==1){p=x;break;}
  init(N,p);
   int pw=1;
  for(int i=n;i>=1;i--)
  {
    ans[i]=big(a,pw,q);
    pw=(pw+ncr(m,n-i+1,p))%p;
  }
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}