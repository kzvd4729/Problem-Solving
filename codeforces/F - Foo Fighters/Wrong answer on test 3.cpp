/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2020 20:21                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 8300 KB                              
*  problem: https://codeforces.com/contest/1148/problem/F
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
#define endl "\n"
#define long long long  
using namespace std;
const int N=3e5;
long a[N+2],b[N+2],n;
bool ck(long msk)
{
  long bl=0;
  for(int i=1;i<=n;i++)
  {
    if(__builtin_popcount(b[i]&msk)%2==0)bl+=a[i];
    else bl-=a[i];
  }
  return bl<0;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
   long msk=(1LL<<62)-1;//cout<<msk<<endl;
   for(int i=0;i<62;i++)
  {
    if(ck(msk^(1LL<i)))
      cout<<(msk^(1LL<i))<<endl,exit(0);
  }
  assert(0);
  return 0;
}