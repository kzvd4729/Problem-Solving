/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/28/2020 20:42                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 93 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1374/problem/B
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
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int tw=0,th=0;
    while(n%2==0)tw++,n/=2;
    while(n%3==0)th++,n/=3;
     if(n>1||th<tw)cout<<-1<<endl;
    else cout<<th+th-tw<<endl;
  }
  return 0;
}