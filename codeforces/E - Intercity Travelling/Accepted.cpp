/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2018 22:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 358 ms                                          memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/1009/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
const long mod=998244353;
long n,arr[N+2],ans,pw[N+2],sq[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   pw[0]=1;
  for(long i=1;i<=N;i++)
    pw[i]=(pw[i-1]*2)%mod;
  sq[1]=1;
  sq[2]=3;
  for(long i=3;i<=N;i++)
    sq[i]=((i-1+2)*pw[i-2])%mod;
   cin>>n;
  for(long i=1;i<=n;i++)
    cin>>arr[i];
  long id=0;
  for(long i=n;i>=1;i--)
  {
    ans+=(arr[i]*sq[++id])%mod;
    ans%=mod;
  }
  cout<<ans%mod<<endl;
  return 0;
}