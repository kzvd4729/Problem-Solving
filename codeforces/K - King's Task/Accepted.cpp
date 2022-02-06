/****************************************************************************************
*  @author: jU_zQxRvd: iShibly, mh755628, kzvd4729           created: Apr/04/2021 14:40                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 46 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1510/problem/K
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
  int a[N+2];
 bool isSorted(vector<int>v)
{
  int n=v.size();
  for(int i=1;i<n;i++)if(v[i]<v[i-1])return false;
  return true;
}
int solve2(vector<int>v)
{
  int n=v.size();
  int f=0;
   int loop=10000;if(isSorted(v))return 0;
  for(int l=1;l<=loop;l++)
  {
    if(f)
    {
      for(int i=0;i<n;i+=2)swap(v[i],v[i+1]);
    }
    else
    {
      for(int i=0;i<n/2;i++)swap(v[i],v[n/2+i]);
    }
    f^=1;
    if(isSorted(v))return l;
  }
  return inf;
}
int solve1(vector<int>v)
{
  int n=v.size();
  int f=1;
   int loop=10000;if(isSorted(v))return 0;
  for(int l=1;l<=loop;l++)
  {
    if(f)
    {
      for(int i=0;i<n;i+=2)swap(v[i],v[i+1]);
    }
    else
    {
      for(int i=0;i<n/2;i++)swap(v[i],v[n/2+i]);
    }
    f^=1;
    if(isSorted(v))return l;
  }
  return inf;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;vector<int>v(n+n);
  for(int i=0;i<n+n;i++)cin>>v[i];
   int mn=min(solve1(v),solve2(v));
  if(mn==inf)mn=-1;
  cout<<mn<<endl;
   return 0;
}