/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/20/2020 20:13                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 2620 ms                                         memory_used: 11900 KB                             
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
int n,k,a[N+2],df,nx[N+2],dp[N+2][N+2][2],nxx[N+2];
int fr[100000+2];
int solve()
{
  dp[n+1][0][1]=1;int kk=k;
  for(int i=n;i>=1;i--)
  {
    for(int k=0;k<=kk;k++)
    {
      for(int f=0;f<=1;f++)
      {
        int ret=dp[i+1][k][f];
        if(k)ret=(ret+dp[nxx[i]][k-1][f])%mod;
        if(k>=2&&nx[i]<=n&&a[nx[i]]-a[i]==df)
          ret=(1LL*ret+1LL*fr[a[nx[i]]]*dp[nx[nx[i]]][k-2][1])%mod;
         dp[i][k][f]=ret;
      }
    }
  }
  return dp[1][k][0];
}
void mem()
{
  for(int i=0;i<=n+1;i++)
  {
    nx[i]=n+1,nxx[i]=n+1;
    for(int j=0;j<=k+1;j++)
      dp[i][j][0]=0,dp[i][j][1]=0;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
  sort(a+1,a+n+1);
   for(int i=1;i<=n;i++)fr[a[i]]++;
   int ans=0;
  for(df=1;df<=100000/(k-1)+1;df++)
  {
    mem();
    int p=1;
    for(int i=1;i<=n;i++)
    {
      while((a[p]-a[i]<df)&&(p<=n))p++;
      if(p>n)break;
      nx[i]=p;
    }
    p=1;
    for(int i=1;i<=n;i++)
    {
      while((a[p]-a[i]<=df)&&(p<=n))p++;
      if(p>n)break;
      nxx[i]=p;
    }
    ans=(ans+1LL*df*solve())%mod;
  }
  cout<<ans<<endl;
  return 0;
}