/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2020 20:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1242/problem/A
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
  long n;cin>>n;int cnt=0;long mn=n;
  for(int i=2;i<=1000000;i++)
  {
    if(n%i)continue;cnt++;mn=min(mn,i*1LL);
    while(n%i==0)n/=i;
  }
  if(n>1)cnt++,mn=min(mn,n*1LL);
  if(cnt>1)cout<<1<<endl;
  else cout<<mn<<endl;
  return 0;
}