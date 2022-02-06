/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/04/2020 10:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/734/problem/B
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
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b,c,d;cin>>a>>b>>c>>d;
   int mn=min({a,c,d});long ans=256LL*mn;
  a-=mn;
  ans+=min(a,b)*32LL;cout<<ans<<endl;
   return 0;
}