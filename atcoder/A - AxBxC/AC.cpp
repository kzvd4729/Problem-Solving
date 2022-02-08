/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-21 15:23:22                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 22 ms                                           memory_used: 3644 KB                              
*  problem: https://atcoder.jp/contests/arc113/tasks/arc113_a
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
const int N=1e6,inf=1e9,mod=998244353;
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int k;cin>>k;
   int cnt=0;
  for(int i=1;i<=k;i++)
  {
    for(int j=1;j<=k;j++)
    {
      if(i*j>k)break;
      for(int l=1;l<=k;l++)
      {
        if(i*j*l>k)break;
        cnt++;
      }
    }
  }
  cout<<cnt<<endl;
     return 0;
}