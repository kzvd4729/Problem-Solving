/****************************************************************************************
*  @author: * kzvd4729                                       created: May/16/2020 19:28                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4700 KB                              
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();long q=5,pt=0;vector<long>ok;
  while(q--)
  {
    long ask=1;
    while(isSafe(ask,pr[pt]))ask*=pr[pt++];
    cout<<"? "<<ask<<endl;
    long gcd;cin>>gcd;
    for(auto x:pr)if(gcd%x==0)ok.push_back(x);
  }
  long d=1;
  for(auto x:ok)
  {
    long ask=1;
    while(isSafe(ask,x))ask*=x;
    cout<<"? "<<ask<<endl;
    long gcd;cin>>gcd;long cnt=0;
    while(gcd%x==0)gcd/=x,cnt++;
    d*=(cnt+1);
  } 
  cout<<"! "<<d*2<<endl;
  return 0;
}