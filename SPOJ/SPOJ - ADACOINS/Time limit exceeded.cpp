/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-06-01 14:53:25                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-ADACOINS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,q,x,lt,rt,qm[N+2];
bitset<N+2>bt;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>q;
  bt[0]=1;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    bt=bt|(bt<<x);
  }
  for(int i=1;i<=N;i++)
    qm[i]=qm[i-1]+bt[i];
  while(q--)
  {
    cin>>lt>>rt;
    cout<<qm[rt]-qm[lt-1]<<endl;
  }
  return 0;
}