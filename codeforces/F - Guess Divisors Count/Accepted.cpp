/****************************************************************************************
*  @author: kzvd4729                                         created: May/17/2020 12:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 4800 KB                              
*  problem: https://codeforces.com/contest/1355/problem/F
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#define long long long
using namespace std;
const long N=1e5;
long vs[N+2];vector<long>pr;
void seive()
{
  for(long i=2;i<=N;i++)
  {
    if(vs[i])continue;pr.push_back(i);
    for(long j=i;j<=N;j+=i)vs[j]=1;
  }
}
const long R=1e18;
bool isSafe(long a,long b)
{
  return R/a>=b;
}
long mx(long p)
{
  long ret=1;
  while(ret*p<=1e9)ret*=p;
  return ret;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  seive();int t;cin>>t;
  while(t--)
  {
    long q=22-5,pt=0;vector<long>ok;
    while(q--)
    {
      long ask=1;
      while(isSafe(ask,pr[pt]))ask*=pr[pt++];
      cout<<"? "<<ask<<endl;
      long gcd;cin>>gcd;
      for(auto x:pr)if(gcd%x==0)ok.push_back(x);
    }
    long d=1;
    for(int i=1;i<ok.size();i+=2)
    {
      long ask=1;
      ask*=mx(ok[i-1]);ask*=mx(ok[i]);
      cout<<"? "<<ask<<endl;
      long gcd;cin>>gcd;long cnt=0;
      while(gcd%ok[i-1]==0)gcd/=ok[i-1],cnt++;
      d*=(cnt+1);cnt=0;
      while(gcd%ok[i]==0)gcd/=ok[i],cnt++;
      d*=(cnt+1);
    }
    if(ok.size()%2)
    {
      long ask=1;
      ask*=mx(ok.back());
      cout<<"? "<<ask<<endl;
      long gcd;cin>>gcd;long cnt=0;
      while(gcd%ok.back()==0)gcd/=ok.back(),cnt++;
      d*=(cnt+1);
    }
    cout<<"! "<<max(d*2,8LL)<<endl;
  }
  return 0;
}