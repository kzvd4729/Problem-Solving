/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/28/2021 22:10                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 124 ms                                          memory_used: 15900 KB                             
*  problem: https://codeforces.com/contest/1264/problem/D1
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
const int N=2e3,inf=1e9,mod=998244353;
 int sm[N+2];
 int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int cal(int lo,int hi)
{
  int tt=sm[hi];
   if(lo)tt-=sm[lo-1];
  return big(2,tt);
}
 string s;int dp[N+2][N+2];
int dfs(int lo,int hi)
{
  if(lo>=hi)return 0;
   if(dp[lo][hi]!=-1)return dp[lo][hi];
   int ret=0;
  if(s[lo]==')')ret=dfs(lo+1,hi);
  else if(s[hi]=='(')ret=dfs(lo,hi-1);
  else 
  {
    if(s[lo]=='?' && s[hi]=='?')
    {
      ret=(cal(lo+1,hi-1)+dfs(lo+1,hi-1))%mod;
      ret=(ret+dfs(lo+1,hi))%mod;
      ret=(ret+dfs(lo,hi-1))%mod;
      ret=(ret-dfs(lo+1,hi-1)+mod)%mod;
    }
    else if(s[lo]=='?')
    {
      ret=(cal(lo+1,hi-1)+dfs(lo+1,hi-1))%mod;
      ret=(ret+dfs(lo+1,hi))%mod;
    }
    else if(s[hi]=='?')
    {
      ret=(cal(lo+1,hi-1)+dfs(lo+1,hi-1))%mod;
      ret=(ret+dfs(lo,hi-1))%mod;
    }
    else ret=(cal(lo+1,hi-1)+dfs(lo+1,hi-1))%mod;
  }
  return dp[lo][hi]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>s;
   memset(dp,-1,sizeof dp);
   if(s[0]=='?')sm[0]=1;
  for(int i=1;i<s.size();i++)
    sm[i]=sm[i-1]+(s[i]=='?');
   cout<<dfs(0,s.size()-1)<<endl;
    return 0;
}