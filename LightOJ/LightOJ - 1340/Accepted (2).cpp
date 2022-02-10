/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-22 14:28:03                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 755                                        memory_used (MB): 3.6                             
*  problem: https://vjudge.net/problem/LightOJ-1340
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5,mod=10000019;

int isPrime[N+2],prime[N+2],id=0;
void seive(int n)
{
  prime[++id]=2;isPrime[1]=1;
  for(int i=4;i<=n;i+=2)isPrime[i]=1;
  int sq=sqrt(n+1);
  for(int i=3;i<=n;i+=2)
  {
    if(isPrime[i])continue;prime[++id]=i;
    if(i>sq)continue;
    for(int j=i*i;j<=n;j+=2*i)
      isPrime[j]=1;
  }
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  seive(N);int t,tc=0;cin>>t;
  while(t--)
  {
    long ans=1;int n,b;cin>>n>>b;
    for(int i=1;prime[i]<=n;i++)
    {
      long ml=prime[i];int cnt=0;
      while(n/ml)
      {
        cnt+=n/ml;ml*=prime[i];
      }
      for(int j=1;j<=cnt/b;j++)
        ans=(ans*prime[i])%mod;
    }
    if(ans==1)ans*=-1;
    cout<<"Case "<<++tc<<": "<<ans<<"\n";
  }
  return 0;
}