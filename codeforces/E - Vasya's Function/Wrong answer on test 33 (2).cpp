/****************************************************************************************
*  @author: kzvd4729                                         created: May/28/2020 17:55                        
*  solution_verdict: Wrong answer on test 33                 language: GNU C++17 (64)                          
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/837/problem/E
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
const int N=1e6;
vector<long>v;
void divisors(long x)
{
  int sq=sqrt(x+1);
  for(int i=1;i<=sq;i++)
  {
    if(x%i)continue;
    v.push_back(i);
    if(i!=x/i)v.push_back(x/i);
  }
  sort(v.begin(),v.end());
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long a,b;cin>>a>>b;divisors(a);
  if(a==1)cout<<b<<endl,exit(0);
   long ans=0;int cur;for(int i=0;i<v.size();i++)if(__gcd(b,v[i])==v[i])cur=i;
  while(b)
  {
    long mx=0,id=v.size();
    for(int i=cur+1;i<v.size();i++)
    {
      __int128 lcm=(v[cur]*v[i])/(__gcd(v[cur],v[i]));
      if(lcm<=b&&b-b%lcm>=mx&&b-b%lcm<b)mx=b-b%lcm,id=i;
    }
    ans+=(b-mx)/v[cur];b=mx,cur=id;
  }
  cout<<ans<<endl;
   return 0;
} 