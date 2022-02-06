/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/26/2020 18:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/213/problem/B
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
const int N=1e2,mod=1e9+7;
int cnt[N+2],n;
int ncr[N+2][N+2],dp[N+2][N+2];
void calNCR(int n)
{
  for(int i=1;i<=n;i++)ncr[i][0]=1;
  ncr[1][1]=1;
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
  }
  ncr[0][0]=1;
}
int dfs(int i,int l)
{
  if(i==10)return l==0;
  if(dp[i][l]!=-1)return dp[i][l];
  int ret=0;
  if(i==0)
  {
    for(int j=cnt[i];j<l;j++)
      ret=(ret+1LL*ncr[l-1][j]*dfs(i+1,l-j))%mod;
  }
  else
  {
    for(int j=cnt[i];j<=l;j++)
      ret=(ret+1LL*ncr[l][j]*dfs(i+1,l-j))%mod;
  }
  return dp[i][l]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;calNCR(N);
  for(int i=0;i<=9;i++)cin>>cnt[i];
   memset(dp,-1,sizeof dp);
  int ret=0;
  for(int l=1;l<=n;l++)
    ret=(ret+dfs(0,l))%mod;
   cout<<ret<<endl;
  return 0;
}