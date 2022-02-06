/****************************************************************************************
*  @author: kzvd4729#                                        created: May/29/2020 16:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/467/problem/B
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
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  int ans=0;
  for(int i=1;i<=m;i++)cin>>aa[i];
   int x;cin>>x;
  for(int i=1;i<=m;i++)
    ans+=(__builtin_popcount((x^aa[i]))<=k);
  cout<<ans<<endl;
    return 0;
}