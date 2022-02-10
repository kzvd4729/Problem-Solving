/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-05 03:33:44                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-LCMSUM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;

//..................................................
vector<int>d[N+2];
void divisors(void)
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)d[j].push_back(i);
  }
}
long phi[N+2];
void calPhi(void)
{
  for(int i=1;i<=N;i++)
  {
    phi[i]+=i;
    for(int j=i+i;j<=N;j+=i)phi[j]-=phi[i];
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  calPhi();divisors();

  for(int i=2;i<=N;i++)phi[i]=1LL*i*phi[i]/2;

  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;long ans=0;
    for(auto k:d[n])
      ans+=(1LL*phi[n/k]*n);
    cout<<ans<<"\n";
  }
  return 0;
}