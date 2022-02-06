/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/23/2020 11:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 467 ms                                          memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/689/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
pair<int,int>pp[N+2];
const int mod=1e9+7;
int big(int b,int p,int m=mod)
{
  int ret=1;
  while(p){if(p&1)ret=(1LL*ret*b)%m;b=(1LL*b*b)%m;p/=2;}
  return ret;
}
int fac[N+2];
void init(int n)
{
  fac[0]=1;
  for(int i=1;i<=n;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
}
int ncr(int n,int r)
{
  int a=fac[n];a=(1LL*a*big(fac[r],mod-2))%mod;
  return (1LL*a*big(fac[n-r],mod-2))%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  int id=0;
  for(int i=1;i<=n;i++)
  {
    int l,r;cin>>l>>r;
    pp[++id]={l,-1};pp[++id]={r,1};
  }
  sort(pp+1,pp+id+1);init(N);
  int cnt=0,ans=0,ls;
  for(int i=1;i<=id;i++)
  {
    if(pp[i].second<0)
    {
      if(cnt>=k)
      {
        int nm=pp[i].first-ls;if(nm==-1)assert(0);
        ans=(1LL*ans+1LL*nm*ncr(cnt,k))%mod;
      }
      cnt++;ls=pp[i].first;
    }
    else
    {
      if(cnt>=k)
      {
        int nm=pp[i].first-ls+1;if(nm==-1)assert(0);
        ans=(1LL*ans+1LL*nm*ncr(cnt,k))%mod;
      }
      cnt--;ls=pp[i].first+1;
    }
  }
  cout<<ans<<endl;
  return 0;
}