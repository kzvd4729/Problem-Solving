/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2021 22:24                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 155 ms                                          memory_used: 47400 KB                             
*  problem: https://codeforces.com/contest/1499/problem/E
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
const int N=1e3,inf=1e9,mod=998244353;
 int dp[N+2][N+2][3][4],n1,n2;
string s[2];
 int dfs(int i,int j,int l,int ms)
{
  if(dp[i][j][l][ms]!=-1)return dp[i][j][l][ms];
  int ret=0;if(ms==3)ret++;
   if(l==2)
  {
    if(i<n1)ret=(ret+dfs(i+1,j,0,ms|(1<<0)))%mod;
    if(j<n2)ret=(ret+dfs(i,j+1,1,ms|(1<<1)))%mod;
  }
  else if(l==0)
  {
    if(i<n1 && s[0][i]!=s[l][i-1])ret=(ret+dfs(i+1,j,0,ms|(1<<0)))%mod;
    if(j<n2 && s[1][j]!=s[l][i-1])ret=(ret+dfs(i,j+1,1,ms|(1<<1)))%mod; 
  }
  else
  {
    if(i<n1 && s[0][i]!=s[l][j-1])ret=(ret+dfs(i+1,j,0,ms|(1<<0)))%mod;
    if(j<n2 && s[1][j]!=s[l][j-1])ret=(ret+dfs(i,j+1,1,ms|(1<<1)))%mod; 
  }
  return dp[i][j][l][ms]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>s[0]>>s[1];
  n1=s[0].size(),n2=s[1].size();
   memset(dp,-1,sizeof dp);
   int ans=0;
  for(int i=0;i<s[0].size();i++)
  {
    for(int j=0;j<s[1].size();j++)
      ans=(ans+dfs(i,j,2,0))%mod;
  }
  cout<<ans<<endl;
   return 0;
}