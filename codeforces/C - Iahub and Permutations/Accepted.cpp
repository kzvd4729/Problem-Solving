/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/16/2018 11:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 31700 KB                             
*  problem: https://codeforces.com/contest/341/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const long N=2e3;
long ncr[N+2][N+2],fac[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(long i=0;i<=N;i++)ncr[i][0]=1;
  for(long i=1;i<=N;i++)
    for(long j=1;j<=i;j++)
      ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
  fac[0]=1;
  for(long i=1;i<=N;i++)fac[i]=(fac[i-1]*i)%mod;
  long n;cin>>n;set<long>st;vector<long>v;
  for(long i=1;i<=n;i++)st.insert(i);
  for(long i=1;i<=n;i++)
  {
    long x;cin>>x;
    if(x==-1)v.push_back(i);
    else st.erase(x);
  }
  long tot=v.size(),fixed=0;
  for(auto x:v)if(st.find(x)!=st.end())fixed++;
  long ans=0;
  for(long i=1;i<=n;i++)
  {
    if(i%2)ans=(ans+ncr[fixed][i]*fac[tot-i])%mod;
    else ans=(ans-ncr[fixed][i]*fac[tot-i])%mod;
  }
  ans=(ans+mod)%mod;
  ans=(fac[tot]-ans+mod)%mod;
  cout<<ans<<endl;
  return 0;
}