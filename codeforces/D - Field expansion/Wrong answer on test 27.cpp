/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/23/2020 17:48                        
*  solution_verdict: Wrong answer on test 27                 language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 17600 KB                             
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
const long inf=1e12;
int a,b,h,w,n;
int aa[N+2];long ml[N+2];
long mul(long a,long b)
{
  if(a*b>inf)return inf;
  return a*b;
}
int dp[40+2][N+2];
int dfs(int i,long one)
{
  if(one>N)one=N;
  if(h*one>=a&&w*(ml[i-1]/one)>=b)return 0;
  if(i>n)return N;
  if(dp[i][one]!=-1)return dp[i][one];
  int ret=N;
  ret=min(ret,1+dfs(i+1,one));
  ret=min(ret,1+dfs(i+1,one*aa[i]));
  return dp[i][one]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>a>>b>>h>>w>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   sort(aa+1,aa+n+1,greater<int>());
  n=min(n,40);
   ml[0]=1;
  for(int i=1;i<=n;i++)ml[i]=mul(ml[i-1],aa[i]);
   memset(dp,-1,sizeof dp);
  int ans=dfs(1,1);if(ans==N)ans=-1;
  cout<<ans<<endl;
   return 0;
}