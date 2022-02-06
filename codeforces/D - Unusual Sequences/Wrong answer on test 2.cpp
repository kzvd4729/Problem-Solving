/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/03/2020 20:20                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/900/problem/D
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
#include<stack>
#define long long long
using namespace std;
const int N=1e6;
vector<int>v;
const int mod=1e9+7;
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
void divisors(int n)
{
  int sq=sqrt(n+1);
  for(int i=1;i<=sq;i++)
  {
    if(n%i)continue;
    v.push_back(i);if(n/i!=i)v.push_back(n/i);
  }
  sort(v.begin(),v.end());
}
long ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int x,y;cin>>x>>y;//if(y%x)cout<<0<<endl,exit(0);
  divisors(y);
  for(int i=v.size()-1;i>=0;i--)
  {
    int now=big(2,(y/v[i])-1);ans[i]=(ans[i]+now)%mod;
    if(v[i]==x)cout<<ans[i]<<endl,exit(0);
    for(int j=0;j<i;j++)
      if(v[i]%v[j]==0)ans[j]=(ans[j]-ans[i]+mod)%mod;
  }
  return 0;
}