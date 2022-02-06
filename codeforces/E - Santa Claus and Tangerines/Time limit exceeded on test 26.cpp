/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/06/2019 17:42                        
*  solution_verdict: Time limit exceeded on test 26          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 44300 KB                             
*  problem: https://codeforces.com/contest/752/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,k,aa[N+2],md,dp[10*N+2];
bitset<10*N+2>vs;
int dfs(int x)
{
  if(x<md)return 0;
  if(vs[x])return dp[x];vs[x]=1;
  dp[x]=1;dp[x]=max(dp[x],dfs(x/2)+dfs((x+1)/2));
  return dp[x];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
  int lo=1,hi=1e7;
  while(hi-lo>2)
  {
    vs.reset();long cnt=0;
    md=(lo+hi)/2;
    for(int i=1;i<=n;i++)
      cnt+=dfs(aa[i])*1LL;
    if(cnt>=k)lo=md;
    else hi=md;
  }
  for(md=hi;md>=lo;md--)
  {
    vs.reset();long cnt=0;
    for(int i=1;i<=n;i++)
      cnt+=dfs(aa[i])*1LL;
    if(cnt>=k)cout<<md<<endl,exit(0);
  }
  cout<<-1<<endl;
  return 0;
}