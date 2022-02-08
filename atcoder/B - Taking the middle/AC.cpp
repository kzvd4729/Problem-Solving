/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-05 16:31:43                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 70 ms                                           memory_used: 5840 KB                              
*  problem: https://atcoder.jp/contests/agc053/tasks/agc053_b
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
   int n;cin>>n;
   vector<int>a(n+n+2);long tt=0;
  for(int i=1;i<=n+n;i++)cin>>a[i],tt+=a[i];
   priority_queue<int,vector<int>,greater<int>>p;
   for(int i=n,j=n+1;i>=1;i--,j++)
  {
    p.push(a[i]);p.push(a[j]);
    tt-=p.top();p.pop();
  }
  cout<<tt<<endl;
      return 0;
}