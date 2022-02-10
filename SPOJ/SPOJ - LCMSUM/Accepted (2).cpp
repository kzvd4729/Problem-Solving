/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-05 03:37:07                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 880                                        memory_used (MB): 960.5                           
*  problem: https://vjudge.net/problem/SPOJ-LCMSUM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;

//..................................................
int d[N+2][240+2],pt[N+2];
void divisors(void)
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)d[j][++pt[j]]=i;
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
    for(int i=1;i<=pt[n];i++)
    {
      int k=d[n][i];ans+=(1LL*phi[n/k]*n);
    }
    cout<<ans<<"\n";
  }
  return 0;
}