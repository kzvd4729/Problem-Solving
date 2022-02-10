/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-22 16:48:25                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 260                                        memory_used (MB): 19.5                            
*  problem: https://vjudge.net/problem/SPOJ-GCDEX
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;

long phi[N+2],res[N+2];
void calPhi(void)
{
  for(int i=1;i<=N;i++)
  {phi[i]+=i;for(int j=i+i;j<=N;j+=i)phi[j]-=phi[i];}
  for(int i=1;i<=N;i++)
  {for(int j=i+i;j<=N;j+=i)res[j]+=i*phi[j/i];}
  for(int i=1;i<=N;i++)res[i]+=res[i-1];
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  calPhi();int n;
  while(cin>>n)
  {
    if(n==0)break;
    cout<<res[n]<<"\n";
  }
  return 0;
}