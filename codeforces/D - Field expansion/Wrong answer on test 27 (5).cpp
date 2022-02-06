/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/23/2020 18:08                        
*  solution_verdict: Wrong answer on test 27                 language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 1700 KB                              
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
const long N=1e5;
const long inf=1e12;
long a,b,h,w,n;
long aa[N+2];long ml[N+2];
long mul(long a,long b)
{
  if(a*b>inf)return inf;
  return a*b;
}
map<long,long>dp[40+2];
long dfs(long i,long one)
{
  if(h*one>=a&&w*(ml[i-1]/one)>=b)return 0;
  if(i>n)return N;
  if(dp[i].count(one))return dp[i][one];
  long ret=N;
  ret=min(ret,1+dfs(i+1,one));
  ret=min(ret,1+dfs(i+1,mul(one,aa[i])));
  return dp[i][one]=ret;
}
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>a>>b>>h>>w>>n;
  for(long i=1;i<=n;i++)cin>>aa[i];
   sort(aa+1,aa+n+1,greater<long>());
  n=min(n,40LL);
   ml[0]=1;
  for(long i=1;i<=n;i++)ml[i]=mul(ml[i-1],aa[i]);
   long ans=dfs(1,1);if(ans>=N)ans=-1;
  cout<<ans<<endl;
   return 0;
}