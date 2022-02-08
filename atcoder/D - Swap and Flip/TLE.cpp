/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-18 19:31:22                      
*  solution_verdict: TLE                                     language: C++14 (GCC 5.4.1)                       
*  run_time: 2104 ms                                         memory_used: 59648 KB                             
*  problem: https://atcoder.jp/contests/keyence2020/tasks/keyence2020_d
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[18+2],bb[18+2],dp[18+2][2][(1<<18)+2],n,pre[18+2][(1<<18)+2];
inline int dfs(int last,int f,int msk)
{
  if(msk==(1<<n)-1)return 0;
  if(dp[last][f][msk]!=-1)return dp[last][f][msk];
  int l=aa[last];if(f)l=bb[last];
  int ret=inf;int cnt=__builtin_popcount(msk);
  for(int i=0;i<n;i++)
  {
    if(msk&(1<<i))continue;
    int p=pre[i][msk]+i;//current position of i
     int fl=(pre[i][msk]+p-cnt)%2;
    int now=aa[i];if(fl)now=bb[i];
    if(now>=l)ret=min(ret,p-cnt+dfs(i,fl,msk|(1<<i)));
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
  for(int i=0;i<n;i++)cin>>aa[i];
  for(int i=0;i<n;i++)cin>>bb[i];
   //for(int i=0;i<n;i++)aa[i]=1+rand()%50;
  //for(int i=0;i<n;i++)bb[i]=1+rand()%50;
   for(int i=0;i<n;i++)
  {
    for(int msk=0;msk<(1<<n);msk++)
    {
      int cnt=0;
      if(msk&(1<<i))continue;
      for(int j=i+1;j<n;j++)
        cnt+=(bool)(msk&(1<<j));
       pre[i][msk]=cnt;
    }
  }
  //cout<<pre[0][14]<<endl;
  memset(dp,-1,sizeof(dp));
  int mn=dfs(0,0,(1<<0));
  for(int i=1;i<n;i++)
    mn=min(mn,i+dfs(i,i%2,(1<<i)));
  if(mn==inf)mn=-1;
  cout<<mn<<endl;
   return 0;
}