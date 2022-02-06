/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/19/2021 20:12                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 31 ms                                           memory_used: 1100 KB                              
*  problem: https://codeforces.com/contest/1514/problem/C
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
  void print(vector<int>v)
{
  int sz=v.size();
  cout<<sz<<endl;
   for(auto x:v)cout<<x<<" ";
    cout<<endl;
   exit(0);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
   vector<int>v;
  for(int i=1;i<n;i++)
    if(__gcd(i,n)==1)v.push_back(i);
    int ml=1;
  for(auto x:v)ml=(1LL*ml*x)%n;
   if(ml==1)print(v);
   v.pop_back();
   ml=1;
  for(auto x:v)ml=(1LL*ml*x)%n;
   if(ml!=1)assert(0);
   print(v);
    return 0;
}