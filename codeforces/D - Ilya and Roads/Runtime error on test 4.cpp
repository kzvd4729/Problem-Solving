/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/15/2018 14:19                        
*  solution_verdict: Runtime error on test 4                 language: GNU C++14                               
*  run_time: 216 ms                                          memory_used: 118100 KB                            
*  problem: https://codeforces.com/contest/313/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5,R=3e2;
const long inf=1e17;
long n,m,k;
vector<long>dp[R+2][R+2];
struct data
{
  long lt,rt,cc;
}aa[N+2];
bool cmp(data A,data B)
{
  return A.rt<B.rt;
}
long dfs(long st,long ls,long kk)
{
  if(kk>=k)return 0;
  if(st>n)return inf;
  if(dp[st][kk][ls]!=-1)return dp[st][kk][ls];
  long here=inf;
  here=min(here,aa[st].cc+dfs(st+1,st,kk+aa[st].rt-max(aa[st].lt-1,aa[ls].rt)));
  here=min(here,dfs(st+1,ls,kk));
  return dp[st][kk][ls]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>m>>k;
  for(long i=1;i<=m;i++)
    cin>>aa[i].lt>>aa[i].rt>>aa[i].cc;
  sort(aa+1,aa+m+1,cmp);
   for(long i=0;i<=R;i++)
  {
    for(long j=0;j<=R;j++)
    {
      dp[i][j].resize(i+1,-1);
    }
  }
  long ans=dfs(1,0,0);if(ans==inf)ans=-1;
  cout<<ans<<endl;
   return 0;
}