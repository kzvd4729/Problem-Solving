/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/23/2020 20:10                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1369/problem/A
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
#define long long long  
using namespace std;
const int N=150000;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    if(n%4==0)cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}