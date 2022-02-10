/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-09 13:33:34                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-simple-game
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
const int N=1e5,mod=1e9+7;
int n,m,k,dp[600+2][10+2][600+600+2];
int dfs(int rm,int pl,int xx)
{
  if(pl==m)return (rm==0)&&((bool)(xx));
  if(dp[rm][pl][xx]!=-1)return dp[rm][pl][xx];
  int ret=0;
  for(int i=1;i<=rm;i++)
    ret=(ret+dfs(rm-i,pl+1,xx^(i-1)))%mod;
  return dp[rm][pl][xx]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>k;
  memset(dp,-1,sizeof dp);
  cout<<dfs(n,0,0)<<endl;

  return 0;
}