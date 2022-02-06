/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/20/2018 13:17                        
*  solution_verdict: Wrong answer on test 14                 language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 62800 KB                             
*  problem: https://codeforces.com/contest/914/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const int N=2e3;
int dp[N+2][N+2][2][2];
int n,k,kk[N+2];
string s;
long dfs(int st,int one,int ck,int f)
{
  if(st>=n)
  {
    if(kk[one]+1==k)return 1;
    else return 0;
  }
  if(dp[st][one][ck][f]!=-1)return dp[st][one][ck][f]*1LL;
  long here=0,now=s[st]-'0';
  if(!ck)
  {
    here=(here+dfs(st+1,one,0,f))%mod;
    here=(here+dfs(st+1,one+1,0,1))%mod;
  }
  else
  {
    if(now==0)here=(here+dfs(st+1,one,1,f))%mod;
    else
    {
      here=(here+dfs(st+1,one,0,f))%mod;
      here=(here+dfs(st+1,one+1,1,1))%mod;
    }
  }
  return dp[st][one][ck][f]=here%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s>>k;
  n=s.size();
    if(k==0)cout<<1<<endl,exit(0);
   for(int i=2;i<=n;i++)
  {
    int bt=__builtin_popcount(i);
    kk[i]=kk[bt]+1;
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,0,1,0)<<endl;
  return 0;
}