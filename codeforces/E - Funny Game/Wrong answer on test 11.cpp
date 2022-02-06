/****************************************************************************************
*  @author: kzvd4729                                         created: May/10/2020 14:29                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/731/problem/E
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
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long sm=0;
  for(int i=1;i<=n;i++)cin>>aa[i],sm+=aa[i];
   cout<<max(sm,-1LL*aa[n])<<endl;
   return 0;
}