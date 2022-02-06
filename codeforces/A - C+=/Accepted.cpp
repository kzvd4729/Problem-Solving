/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/18/2020 20:49                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1368/problem/A
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
    long a,b,n;cin>>a>>b>>n;
     int cnt=0;
    while(true)
    {
      if(max(a,b)>n)break;
      if(a<=b)a+=b;else b+=a;
      cnt++;
    }
    cout<<cnt<<"\n";
  }
     return 0;
}