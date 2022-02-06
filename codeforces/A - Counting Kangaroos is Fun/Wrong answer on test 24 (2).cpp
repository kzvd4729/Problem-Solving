/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/23/2020 13:47                        
*  solution_verdict: Wrong answer on test 24                 language: GNU C++17                               
*  run_time: 186 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/372/problem/A
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
int a[N+2],n;
bool ck(int md)
{
  for(int i=n;i>n-md;i--)
  {
    if(a[i]<a[md]*2)return false;
    md--;
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  sort(a+1,a+n+1);
    int lo=0,hi=n/2,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ck(md))lo=md;else hi=md;
  }
  for(md=hi;md>=lo;md--)if(ck(md))break;
  cout<<n-md<<endl;
   return 0;
}