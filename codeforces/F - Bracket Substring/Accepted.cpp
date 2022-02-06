/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2018 20:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 64500 KB                             
*  problem: https://codeforces.com/contest/1015/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const int N=2e2;
int n,kmp[N+2],ln;
long dp[N+2][N+2][N+2];
string s;
long dfs(int ii,int mt,int bl)
{
  if(ii==n&&mt>=ln&&bl==0)return 1LL;
  if(ii>=n)return 0LL;
  if(dp[ii][mt][bl]!=-1)return dp[ii][mt][bl];
  long here=0;int now;
  if(mt>=ln)
  {
    here=(here+dfs(ii+1,mt,bl+1))%mod;
    if(bl)here=(here+dfs(ii+1,mt,bl-1))%mod;
  }
  else
  {
    if(s[mt]=='(')
    {
      here=(here+dfs(ii+1,mt+1,bl+1))%mod;
      now=mt;
      while(true)
      {
        if(s[now]==')')
        {
          now++;
          break;
        }
        if(!now)break;
        now=kmp[now-1];
      }
      if(bl)here=(here+dfs(ii+1,now,bl-1))%mod;
    }
    else
    {
      if(bl)here=(here+dfs(ii+1,mt+1,bl-1))%mod;
      now=mt;
      while(true)
      {
        if(s[now]=='(')
        {
          now++;
          break;
        }
        if(!now)break;
        now=kmp[now-1];
      }
      here=(here+dfs(ii+1,now,bl+1))%mod;
    }
  }
  return dp[ii][mt][bl]=here%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);
   cin>>n>>s;
  for(int i=1;i<s.size();i++)
  {
    int now=kmp[i-1];
    while(true)
    {
      if(s[i]==s[now])
      {
        kmp[i]=now+1;
        break;
      }
      if(!now)break;
      now=kmp[now-1];
    }
  }
  n+=n;
  ln=s.size();
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,0,0)<<endl;
  return 0;
}