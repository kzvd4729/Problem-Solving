/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2020 23:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 5600 KB                              
*  problem: https://codeforces.com/contest/1178/problem/F1
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
#define long long long
using namespace std;
const int N=5e2,mod=998244353;
int n,m,aa[N+2],mn[N+2][N+2],po[N+2],dp[N+2][N+2];
int dfs(int lo,int hi)
{
  if(lo>=hi)return 1;
  if(dp[lo][hi]!=-1)return dp[lo][hi];
  int id=po[mn[lo][hi]];
  int ad=0,ret=0;
  for(int j=id;j<=hi;j++)
    ad=(ad+1LL*dfs(id+1,j)*dfs(j+1,hi))%mod;
  for(int i=lo;i<=id;i++)
    ret=(ret+((1LL*dfs(lo,i-1)*dfs(i,id-1))%mod)*ad)%mod;
  return dp[lo][hi]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>aa[i],po[aa[i]]=i;
  for(int i=1;i<=n;i++)
  {
    mn[i][i]=aa[i];
    for(int j=i+1;j<=n;j++)
      mn[i][j]=min(mn[i][j-1],aa[j]);
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,n)<<endl;
  return 0;
}