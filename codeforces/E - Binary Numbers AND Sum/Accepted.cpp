/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/12/2018 21:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1066/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
const long mod=998244353;
long pw[N+2],qm[N+2];
string a,b;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   pw[0]=1LL;
  for(long i=1;i<=N;i++)pw[i]=(pw[i-1]*2LL)%mod;
   long n,m;cin>>n>>m;
  cin>>a>>b;
  for(long i=1;i<=m;i++)
  {
    qm[i]=qm[i-1];
    if(b[i-1]=='1')qm[i]++;
  }
  long ans=0;
  for(long i=1;i<=n;i++)
  {
    if(a[i-1]=='0')continue;
    long id=m-n+i;
    if(id<0)continue;
    ans=(ans+qm[id]*pw[n-i])%mod;
  }
  cout<<ans<<endl;
  return 0;
}