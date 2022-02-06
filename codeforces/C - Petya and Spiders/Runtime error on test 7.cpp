/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/07/2020 19:41                        
*  solution_verdict: Runtime error on test 7                 language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 43100 KB                             
*  problem: https://codeforces.com/contest/111/problem/C
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
int n,m;
int s(int msk)
{
  return msk>>m;
}
int dp[40+2][(1<<18)+2];
int dfs(int i,int j,int msk)
{
  if(i==n)
  {
    for(int j=m;j<3*m;j++)if(msk&(1<<j))return -N;
    return 0;
  }
  if(dp[i*n+j][msk]!=-1)return dp[i*n+j][msk];
  int ret=-N;
  if(j==m-1)
  {
    if(msk&(1<<(m+j)))ret=max(ret,dfs(i+1,0,s(msk)));
    else
    {
      ret=max(ret,dfs(i+1,0,s(msk|(1<<(m+j)))));
      ret=max(ret,1+dfs(i+1,0,s(msk|(1<<(m+j+m)))));
      if(j>0&&(msk&(1<<(m+j-1))))ret=max(ret,1+dfs(i+1,0,s(msk)));
      if(i>0&&(msk&(1<<j)))ret=max(ret,1+dfs(i+1,0,s(msk)));
    }
  }
  else
  {
    if(msk&(1<<(m+j)))ret=max(ret,dfs(i,j+1,msk));
    else
    {
      ret=max(ret,dfs(i,j+1,msk|(1<<(m+j))));
      ret=max(ret,1+dfs(i,j+1,msk|(1<<(m+j+1))));
      ret=max(ret,1+dfs(i,j+1,msk|(1<<(m+j+m))));
      if(j>0&&(msk&(1<<(m+j-1))))ret=max(ret,1+dfs(i,j+1,msk));
      if(i>0&&(msk&(1<<j)))ret=max(ret,1+dfs(i,j+1,msk));
    }
  }
  return dp[i*n+j][msk]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;if(n<m)swap(n,m);
  memset(dp,-1,sizeof dp);
  cout<<dfs(0,0,0)<<endl;
    return 0;
}