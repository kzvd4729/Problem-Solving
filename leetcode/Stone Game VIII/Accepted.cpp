/****************************************************************************************
*  @author: kzvd4729                                         created: 05/29/2021 23:07                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 156 ms                                          memory_used: 93.6 MB                              
*  problem: https://leetcode.com/problems/stone-game-viii
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
const long N=1e5,inf=1e9,mod=1000000007;
long n,a[N+2],dp[N+2][2],vs[N+2][2];
const long Alice=0,Bob=1;
long dfs(long i,long tr)
{
  if(vs[i][tr])return dp[i][tr];
  vs[i][tr]=1;
  if(tr==Alice)
  {
    if(i==n)return dp[i][tr]=a[n];
    long ret=dfs(i+1,tr);
    ret=max(ret,a[i]-dfs(i+1,tr^1));
    return dp[i][tr]=ret;
  }
  else 
  {
    if(i==n)return dp[i][tr]=a[n];
    long ret=dfs(i+1,tr);
    ret=max(ret,a[i]-dfs(i+1,tr^1));
    return dp[i][tr]=ret;
  }
}
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
                n=stones.size();
        for(int i=1;i<=n;i++)a[i]=stones[i-1];
        for(long i=1;i<=n;i++)a[i]+=a[i-1];
      memset(vs,0,sizeof vs);
      return dfs(2,0);
            }
};