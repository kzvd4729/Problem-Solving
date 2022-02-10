/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-22 16:05:11                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 170                                        memory_used (MB): 19.5                            
*  problem: https://vjudge.net/problem/SPOJ-LCMSUM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;

long phi[N+2],res[N+2];
void calPhi(void)
{
  for(int i=1;i<=N;i++)
  {
    phi[i]+=i;
    for(int j=i+i;j<=N;j+=i)phi[j]-=phi[i];
  }
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)res[j]+=i*phi[i];
  }
  for(int i=1;i<=N;i++)res[i]=(res[i]+1)/2;
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  calPhi();int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;cout<<res[n]*n<<"\n";
  }
  return 0;
}