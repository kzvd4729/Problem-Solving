/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/20/2019 17:45                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/616/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
long sum,n;
/**************** Progressions *******************/
long AP(long n,long first,long df)
{
  long ret=((2*first)%mod+(n-1)%mod*df%mod)%mod;
  return ((ret*n%mod)%mod*500000004LL)%mod;
}
/////////////////////////////////////////////////
void brut(long x)
{
  for(long i=1;i<=x;i++)
    sum=(sum+n%i)%mod;
  cout<<sum<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long m;cin>>n>>m;
  if(m>n)sum=(n%mod*(m-n)%mod)%mod;
  long ls=min(m,n-1);
  for(long i=2; ;i++)
  {
    if(ls<=10000000)brut(ls);
    long es=(n+i)/i;
    if(ls<es)continue;
    sum=(sum+AP(ls-es+1,n%ls,i-1))%mod;
    ls=es-1;
  }
  return 0;
}