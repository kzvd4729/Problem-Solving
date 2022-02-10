/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-26 21:09:35                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 20                                         memory_used (MB): 16.4                            
*  problem: https://vjudge.net/problem/SPOJ-NAJPWG
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
long qm[N+2];
/*********** Eular Phi **********/
int Phi[N+2];
void PHI(int n)
{
  for(int i=1;i<=n;i++)
  {
    Phi[i]+=i;
    for(int j=i+i;j<=n;j+=i)
      Phi[j]-=Phi[i];
  }
}
//n*((p-1)/p) such that p|n
//////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  PHI(N);
  for(int i=2;i<=N;i++)
    qm[i]=qm[i-1]+i-Phi[i];
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;cout<<"Case "<<++tc<<": ";
    cout<<qm[n]<<"\n";
  }
  return 0;
}