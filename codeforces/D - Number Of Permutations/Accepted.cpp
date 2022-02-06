/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/22/2019 21:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/1207/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
const long mod=998244353;
long fac[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   fac[0]=1;
  for(int i=1;i<=N;i++)
    fac[i]=(fac[i-1]*i)%mod;
   int n;cin>>n;vector<pair<int,int> >v(n);
  for(int i=0;i<n;i++)
    cin>>v[i].first>>v[i].second;
  sort(v.begin(),v.end());
  long ans=fac[n],sub=1;
  int cnt=0;
  for(int i=1;i<n;i++)
  {
    if(v[i].first==v[i-1].first)cnt++;
    else
    {
      sub=(sub*fac[cnt+1])%mod;
      cnt=0;;
    }
  }
  if(cnt)sub=(sub*fac[cnt+1])%mod;
  ans=(ans-sub+mod)%mod;
   for(int i=0;i<n;i++)
    swap(v[i].first,v[i].second);
   sort(v.begin(),v.end());
  cnt=0;sub=1;
  for(int i=1;i<n;i++)
  {
    if(v[i].first==v[i-1].first)cnt++;
    else
    {
      sub=(sub*fac[cnt+1])%mod;
      cnt=0;
    }
  }
  if(cnt)sub=(sub*fac[cnt+1])%mod;
  ans=(ans-sub+mod)%mod;
    int f=0;
  for(int i=1;i<n;i++)
    if(v[i].first<v[i-1].first||v[i].second<v[i-1].second)f=1;
  if(f)cout<<ans<<endl,exit(0);
    cnt=0,sub=1;
  for(int i=1;i<n;i++)
  {
    if(v[i]==v[i-1])cnt++;
    else
    {
      sub=(sub*fac[cnt+1])%mod;
      cnt=0;f=1;
    }
  }
  if(cnt)sub=(sub*fac[cnt+1])%mod;
  ans=(ans+sub+mod)%mod;
   cout<<ans<<endl;
   return 0;
}