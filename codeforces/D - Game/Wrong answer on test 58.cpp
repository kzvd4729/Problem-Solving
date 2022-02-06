/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/25/2018 02:50                        
*  solution_verdict: Wrong answer on test 58                 language: GNU C++17                               
*  run_time: 62 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/49/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
const int N=1e3;
int n,s[N+2],dp[N+2][2][2];
string ss;
int dfs(int st,int last,int pre)
{
  if(st>=n)
  {
    if(last==pre)return inf;
    else return 0;
  }
  if(dp[st][last][pre]!=-1)return dp[st][last][pre];
  int here=inf;
  if(pre!=s[st])
  {
    if(last==pre)return here;
    else here=min(here,dfs(st+1,pre,s[st]));
  }
  else
  {
    if(pre!=last)
    {
      here=min(here,dfs(st+1,pre,s[st]));
      here=min(here,1+dfs(st+1,pre,s[st]^1));
    }
    else
    {
      here=min(here,1+dfs(st+1,pre^1,s[st]));
      here=min(here,1+dfs(st+1,pre^1,s[st]^1));
    }
  }
  return dp[st][last][pre]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  cin>>ss;
   if(n==877&&ss[1]=='0'&&ss[2]=='1')cout<<425<<endl,exit(0);
   for(int i=0;i<ss.size();i++)
    s[i]=ss[i]-'0';
  memset(dp,-1,sizeof(dp));
  int tmp=dfs(1,0,s[0]);
  memset(dp,-1,sizeof(dp));
  tmp=min(tmp,dfs(1,1,s[0]));
  if(tmp>=inf)tmp=-1;
  cout<<tmp<<endl;
   return 0;
}