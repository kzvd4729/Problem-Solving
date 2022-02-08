/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-09 15:57:45                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 296 ms                                          memory_used: 3656 KB                              
*  problem: https://atcoder.jp/contests/arc116/tasks/arc116_a
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
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
   while(t--)
  {
    long n;cin>>n;
     if(n%4==0)cout<<"Even"<<endl;
    else if(n%2==0)cout<<"Same"<<endl;
    else cout<<"Odd"<<endl;
  }
       return 0;
}