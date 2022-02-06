/****************************************************************************************
*  @author: kzvd4729#                                        created: Sep/25/2020 13:47                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 93 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1420/problem/C1
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
const int N=1e6;
const int ng=0,ps=1;
long dp[N+2][2];
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int t;cin>>t;
  while(t--)
  { 
    int n,q;cin>>n>>q;
    dp[0][ng]=0;dp[0][ps]=-1e18;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      dp[i][ng]=dp[i-1][ng];dp[i][ps]=dp[i-1][ps];

      dp[i][ng]=max(dp[i][ng],dp[i-1][ps]-x);
      dp[i][ps]=max(dp[i][ps],dp[i-1][ng]+x);
    }
    cout<<max(dp[n][ps],dp[n][ng])<<'\n';
  }
  return 0;
}