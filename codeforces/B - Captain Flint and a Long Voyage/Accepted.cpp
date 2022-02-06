/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2020 10:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1388/problem/B
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
const int N=2e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int et=(n+3)/4;
    for(int i=1;i<=n-et;i++)cout<<9;
    for(int i=1;i<=et;i++)cout<<8;
    cout<<'\n';
  }
  return 0;
}