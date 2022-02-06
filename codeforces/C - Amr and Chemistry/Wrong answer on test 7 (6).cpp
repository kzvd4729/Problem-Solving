/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2018 16:42                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 7100 KB                              
*  problem: https://codeforces.com/contest/558/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
const long inf=1e9;
long aa[N+N+N+2],n,mx,dp1[N+N+N+2],dp2[N+N+N+2];
long dfs1(long x)
{
  //cout<<x<<endl;
  if(x==mx)return 0;
  if(dp1[x]!=-1)return dp1[x];
  dp1[x]=inf;
  dp1[x]=1+dfs1(x/2);
  if(x%2==1&&x>1)
    dp1[x]=min(dp1[x],2+dfs1(x-1));
  return dp1[x];
}
long dfs2(long x)
{
  if(x==mx)return 0;
  if(x>N+N+N)return inf;
  if(dp2[x]!=-1)return dp2[x];
  dp2[x]=inf;
  dp2[x]=1+dfs2(x*2);
  if(x%2==1&&x>1)
    dp2[x]=min(dp2[x],3+dfs2(x-1+x-1));
  return dp2[x];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(long i=1;i<=n;i++)
  {
    cin>>aa[i];mx=max(mx,aa[i]);
  }
  long ans=1e9;
  while(mx)
  {
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    long cnt=0;
    for(int i=1;i<=n;i++)
    {
      if(aa[i]>mx)cnt+=dfs1(aa[i]);
      else cnt+=dfs2(aa[i]);
    }
    ans=min(ans,cnt);
    mx/=2;
  }
  cout<<ans<<endl;
  return 0;
}