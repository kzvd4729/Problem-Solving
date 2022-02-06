/****************************************************************************************
*  @author: kzvd4729                                         created: May/28/2020 20:40                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1359/problem/A
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,k;cin>>n>>m>>k;
    int mx=min(n/k,m);
    m-=mx;int mn=(m+k-2)/(k-1);
    cout<<mx-mn<<endl;
  }
  return 0;
}