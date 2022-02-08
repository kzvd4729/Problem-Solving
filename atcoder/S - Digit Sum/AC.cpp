/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-11 10:09:06                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 82 ms                                           memory_used: 17024 KB                             
*  problem: https://atcoder.jp/contests/dp/tasks/dp_s
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1e9+7;
string s;int d;long dp[10002][102][2];
long dfs(int st,int md,int ck)
{
  if(st>=s.size())return !md;
  if(dp[st][md][ck]!=-1)return dp[st][md][ck];
  int x=s[st]-'0';long now=0;
  if(!ck)
  {
    for(int i=0;i<=9;i++)
      now=(now+dfs(st+1,(md+i)%d,0))%mod;
  }
  else
  {
    for(int i=0;i<x;i++)
      now=(now+dfs(st+1,(md+i)%d,0))%mod;
    now=(now+dfs(st+1,(md+x)%d,1))%mod;
  }
  return dp[st][md][ck]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>s>>d;memset(dp,-1,sizeof(dp));
  cout<<(dfs(0,0,1)-1+mod)%mod<<endl;
   return 0;
}