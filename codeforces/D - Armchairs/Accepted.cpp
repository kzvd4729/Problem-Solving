/****************************************************************************************
*  @author: kzvd4729#                                        created: May/26/2021 14:56                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 451 ms                                          memory_used: 99000 KB                             
*  problem: https://codeforces.com/contest/1525/problem/D
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
const int N=5000,inf=1e9,mod=998244353;
 int a[N+2],n,dp[N+2][N+2];
 int dfs(int i,int j)
{
  if(i>n)return 0;
   if(dp[i][j]!=-1)return dp[i][j];
  if(a[i]==0)return dp[i][j]=dfs(i+1,j);
    if(j>n)return inf;
    int ret=dfs(i,j+1);
  if(a[j]==0)ret=min(ret,abs(i-j)+dfs(i+1,j+1));
   return dp[i][j]=ret;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
    memset(dp,-1,sizeof dp);
  cout<<dfs(1,1)<<endl;
    return 0;
}