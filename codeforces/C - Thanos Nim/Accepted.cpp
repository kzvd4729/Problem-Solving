/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/30/2020 19:44                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 4500 KB                              
*  problem: https://codeforces.com/contest/1161/problem/C
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
#define long long long
using namespace std;
const int N=2e5;
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  int mn=50;
  for(int i=1;i<=n;i++)mn=min(mn,a[i]);
  int cnt=0;
  for(int i=1;i<=n;i++)cnt+=(mn==a[i]);
   if(cnt<=n/2)cout<<"Alice\n";else cout<<"Bob\n";
    return 0;
}