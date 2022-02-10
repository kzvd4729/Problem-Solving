/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-17 23:13:07                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 748                                        memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1032
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,n,tc;
long dp[33][2][2][40];
vector<int>now;
vector<int>make_binary(int x)
{
  vector<int>v;
  for(int i=31;i>=0;i--)
    v.push_back(bool(x&(1<<i)));
  return v;
}
long dfs(int st,int ck,int last,int ret)
{
  if(st>31)return ret*1LL;
  if(dp[st][ck][last][ret]!=-1)return dp[st][ck][last][ret];
  long cnt=0;
  if(ck==0)
  {
    if(last==0)
    {
      cnt+=dfs(st+1,0,0,ret);
      cnt+=dfs(st+1,0,1,ret);
    }
    else
    {
      cnt+=dfs(st+1,0,0,ret);
      cnt+=dfs(st+1,0,1,ret+1);
    }
  }
  else
  {
    if(now[st]==0)
      cnt+=dfs(st+1,1,0,ret);
    else
    {
      if(last==0)
      {
        cnt+=dfs(st+1,0,0,ret);
        cnt+=dfs(st+1,1,1,ret);
      }
      else
      {
        cnt+=dfs(st+1,0,0,ret);
        cnt+=dfs(st+1,1,1,ret+1);
      }
    }
  }
  return dp[st][ck][last][ret]=cnt;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n;
    now=make_binary(n);
    memset(dp,-1,sizeof(dp));
    cout<<"Case "<<++tc<<": "<<dfs(0,1,0,0)<<endl;
  }
  return 0;
}