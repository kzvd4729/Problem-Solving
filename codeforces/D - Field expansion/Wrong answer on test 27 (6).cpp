/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/23/2020 18:20                        
*  solution_verdict: Wrong answer on test 27                 language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 2900 KB                              
*  problem: https://codeforces.com/contest/799/problem/D
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
const int N=1e5;
int a,b,h,w,n;
int aa[N+2];
int mul(int a,int b)
{
  if(1LL*a*b>N)return N;
  return a*b;
}
map<int,int>dp[N+2];
int dfs(int i,int h,int w)
{
  if(h>=a&&w>=b)return 0;
  if(i>n)return N;
  if(dp[h].count(w))return dp[h][w];
  int ret=N;
  ret=min(ret,1+dfs(i+1,mul(h,aa[i]),w));
  ret=min(ret,1+dfs(i+1,h,mul(w,aa[i])));
  return dp[h][w]=ret;
}
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>a>>b>>h>>w>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   sort(aa+1,aa+n+1,greater<int>());
  n=min(n,40);
   int ans=dfs(1,h,w);if(ans>=N)ans=-1;
  cout<<ans<<endl;
   return 0;
}