/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-24 22:02:05                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 324 ms                                          memory_used: 7772 KB                              
*  problem: https://atcoder.jp/contests/abc192/tasks/abc192_f
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
const int N=1e6,inf=1e9,mod=998244353;
 int a[N+2],ex,n,m;
int dp[100+2][100+2][100+2];
int dfs(int i,int k,int r)
{
  if(i>n)
  {
    if((k==0) && (r==ex))return 0;
    else return -(inf+10);
  }
   if(dp[i][k][r]!=-1)return dp[i][k][r];
   int ret=dfs(i+1,k,r);
  if(k)ret=max(ret,a[i]+dfs(i+1,k-1,(r+a[i])%m));
   return dp[i][k][r]=ret;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long x;cin>>n>>x;
   for(int i=1;i<=n;i++)cin>>a[i];
   long ans=1LL*inf*inf;
  for(int k=1;k<=n;k++)
  {
    ex=x%k,m=k;memset(dp,-1,sizeof dp);
     int sm=dfs(1,k,0);
    if(sm<0)continue;
     //cout<<k<<" "<<sm<<endl;
    //cout<<ex<<" "<<sm<<" "<<sm%k<<endl;
     ans=min(ans,(x-sm)/k);
  }
  cout<<ans<<endl;
     return 0;
}