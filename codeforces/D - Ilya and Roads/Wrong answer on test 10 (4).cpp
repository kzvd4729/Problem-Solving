/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/15/2018 14:36                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++17                               
*  run_time: 280 ms                                          memory_used: 218200 KB                            
*  problem: https://codeforces.com/contest/313/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5,R=3e2;
const long inf=1e15;
long n,m,k;
long dp[R+2][R+2][R+2];
struct _data
{
  long lt,rt,cc;
}aa[N+2];
bool cmp(_data A,_data B)
{
  return A.rt<B.rt;
}
long dfs(long st,long ls,long kk)
{
  if(kk>=k)return 0;
  if(st>m)return inf;
  if(dp[st][kk][ls]!=-1)return dp[st][kk][ls];
  long here=inf;
  here=min(here,aa[st].cc+dfs(st+1LL,st,kk+aa[st].rt-max(aa[st].lt-1LL,aa[ls].rt)));
  here=min(here,dfs(st+1LL,ls,kk));
  return dp[st][kk][ls]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>m>>k;
  for(long i=1;i<=m;i++)
    cin>>aa[i].lt>>aa[i].rt>>aa[i].cc;
  sort(aa+1,aa+m+1,cmp);
   memset(dp,-1,sizeof(dp));
  long ans=dfs(1,0,0);if(ans==inf)ans=-1;
  cout<<ans<<endl;
   return 0;
}