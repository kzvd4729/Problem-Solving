/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/19/2020 16:59                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1379/problem/F1
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
#include<deque>
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,q;cin>>n>>m>>q;
  map<pair<int,int>,int>mp;
  while(q--)
  {
    int a,b;cin>>a>>b;
     int f=0;
    if(mp.count({a,b+2})&&mp.count({a+1,b+1})&&mp.count({a-1,b+1}))
      f=1;
    if(mp.count({a,b-2})&&mp.count({a-1,b+1})&&mp.count({a-1,b-1}))
      f=1;
    if(mp.count({a,b-2})&&mp.count({a+1,b-1})&&mp.count({a-1,b-1}))
      f=1;
    if(mp.count({a+2,b})&&mp.count({a+1,b+1})&&mp.count({a+1,b-1}))
      f=1;
     if(f)cout<<"YES\n";
    else cout<<"NO\n";
     mp[{a,b}]=1;
  }
   return 0;
}