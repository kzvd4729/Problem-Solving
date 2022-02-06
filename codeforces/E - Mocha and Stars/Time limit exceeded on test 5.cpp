/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/25/2021 14:27                        
*  solution_verdict: Time limit exceeded on test 5           language: GNU C++17 (64)                          
*  run_time: 2000 ms                                         memory_used: 40200 KB                             
*  problem: https://codeforces.com/contest/1559/problem/E
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
 const int N=1e6,inf=1e9,mod=998244353;
int l[N+2],r[N+2];
 int mb[N+2],vis[N+2];
void mobius()
{
  for(int i=1;i<=N;i++)mb[i]=1;
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      mb[j]*=-1;vis[j]=1;
      if(i<=30000&&(j%(i*i)==0))mb[j]=0;
    }
  }
}
int x,n,m,dp[50+2][100000+2];
int dfs(int i,int rm)
{
  if(rm<0)return 0;
  if(i>n)return 1;
   if(dp[i][rm]!=-1)return dp[i][rm];
   int ret=0;
  for(int j=x;j<=m;j+=x)
  {
    if(j>=l[i] && j<=r[i])
    {
      ret=(ret+dfs(i+1,rm-j/x))%mod;
    }
  }
  return dp[i][rm]=ret;
}
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
   mobius();
  //for(int i=1;i<=10;i++)cout<<mb[i]<<" ";cout<<endl;
   int ans=0;
  for(int i=1;i<=m;i++)
  {
    x=i;
    for(int j=0;j<=n+1;j++)for(int k=0;k<=m/i+1;k++)dp[j][k]=-1;
    ans=(ans+dfs(1,m/i)*mb[i])%mod;
  }
  cout<<(ans+mod)%mod<<endl;
  return 0;
}