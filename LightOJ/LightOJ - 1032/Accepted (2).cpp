/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-24 19:56:33                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 132                                        memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1032
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,n,tc;
long dp[35][2][2][35];
vector<int>bin;
long dfs(int st,int ck,int last,int ret)
{
  if(st==32)return ret;
  if(dp[st][ck][last][ret]!=-1)return dp[st][ck][last][ret];
  long cnt=0;
  if(ck==0)
  {
    cnt+=dfs(st+1,0,0,ret)*1LL;
    if(last==1)cnt+=dfs(st+1,0,1,ret+1)*1LL;
    else cnt+=dfs(st+1,0,1,ret)*1LL;
  }
  else
  {
    if(bin[st]==0)
      cnt+=dfs(st+1,1,0,ret)*1LL;
    else
    {
      cnt+=dfs(st+1,0,0,ret)*1LL;
      if(last==1)cnt+=dfs(st+1,1,1,ret+1)*1LL;
      else cnt+=dfs(st+1,1,1,ret)*1LL;
    }
  }
  return dp[st][ck][last][ret]=cnt;
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    bin.clear();
    for(int i=31;i>=0;i--)
      bin.push_back((n&(1<<i))?1:0);

    memset(dp,-1,sizeof(dp));
    printf("Case %d: %lld\n",++tc,dfs(0,1,0,0));
  }
  return 0;
}