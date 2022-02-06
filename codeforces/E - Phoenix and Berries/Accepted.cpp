/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/08/2020 20:10                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 935 ms                                          memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/1348/problem/E
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=5e2;
int a[N+2],b[N+2],k,n;
int sm,dp[N+2][N+2];
bool dfs(int i,int ra,int rb)
{
  if(ra+rb>sm)return false;if(ra+rb<sm)return true;
  if(i>n)return false;
  if(dp[i][ra]!=-1)return dp[i][ra];
  bool ret=dfs(i+1,ra,rb);
  for(int j=1;j<=min(k,a[i]);j++)
    if(b[i]>=k-j)ret|=dfs(i+1,(ra-j+k+k)%k,(rb-(k-j)+k+k)%k);
  return dp[i][ra]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
   long ans=0,ta=0,tb=0;
  for(int i=1;i<=n;i++)ta+=a[i],tb+=b[i];
  ans+=ta/k;ta%=k;ans+=tb/k;tb%=k;
    sm=ta+tb;memset(dp,-1,sizeof dp);
  cout<<ans+dfs(1,ta,tb)<<endl;
   return 0;
}