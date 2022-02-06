/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/20/2020 19:03                        
*  solution_verdict: Time limit exceeded on test 5           language: GNU C++14                               
*  run_time: 5000 ms                                         memory_used: 11500 KB                             
*  problem: https://codeforces.com/contest/1188/problem/C
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
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e3,mod=998244353;
int n,k,a[N+2],df,nx[N+2],dp[N+2][N+2][2];
int dfs(int i,int k,int f)
{
  if(k<0)return 0;
  if(i>n)return (k==0)*f;
   //if(dp[i][k][f]!=-1)return dp[i][k][f];
   int now=dfs(i+1,k,f);
  if(nx[i]!=-1)now=(now+dfs(nx[i],k-1,(a[nx[i]]-a[i]==df)|f))%mod;
   return dp[i][k][f]=now;
}
void mem()
{
  for(int i=0;i<=n+1;i++)
  {
    nx[i]=-1;
    for(int j=0;j<=k+1;j++)
      dp[i][j][0]=-1,dp[i][j][1]=-1;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
  sort(a+1,a+n+1);
   int ans=0;
  for(df=1;df<=100000;df++)
  {
    mem();
    int p=1;
    for(int i=1;i<=n;i++)
    {
      while(a[p]-a[i]<df&&p<=n)p++;
      if(p>n)break;
       nx[i]=p;
    }
    int ret=0;
    for(int i=1;i<=n;i++)
      ret=(ret+dfs(i,k-1,0))%mod;
    ans=(ans+1LL*df*ret)%mod;
   }
  cout<<ans<<endl;
  return 0;
}