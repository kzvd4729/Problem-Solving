/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2020 21:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1169 ms                                         memory_used: 134600 KB                            
*  problem: https://codeforces.com/contest/1316/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
const long inf=1e18;
long aa[N+2],mt[N+2][10+2],n,p,k,dp[N+2][128+2];
struct data
{
  long ad,po[10+2];
}pp[N+2];
bool cmp(data a,data b)
{
  return a.ad>b.ad;
}
long dfs(long id,long msk,long tkn)
{
  if(id>n)
  {
    if(tkn==p)return 0;
    else return -inf;
  }
  if(dp[id][msk]!=-1)return dp[id][msk];
  long ret=0;
  if(id<=k+tkn)
  {
    ret=max(ret,pp[id].ad+dfs(id+1,msk,tkn));
    for(long j=0;j<p;j++)
    {
      if(msk&(1<<j))continue;
      ret=max(ret,pp[id].po[j]+dfs(id+1,msk|(1<<j),tkn+1));
    }
  }
  else
  {
    ret=max(ret,dfs(id+1,msk,tkn));
    for(long j=0;j<p;j++)
    {
      if(msk&(1<<j))continue;
      ret=max(ret,pp[id].po[j]+dfs(id+1,msk|(1<<j),tkn+1));
    }
  }
  return dp[id][msk]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>p>>k;
  for(long i=1;i<=n;i++)cin>>pp[i].ad;
   for(long i=1;i<=n;i++)
  {
    for(long j=0;j<p;j++)cin>>pp[i].po[j];
  }
  sort(pp+1,pp+n+1,cmp);memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0,0)<<endl;
   return 0;
}