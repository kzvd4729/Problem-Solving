/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/09/2018 00:44                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 41900 KB                             
*  problem: https://codeforces.com/contest/133/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,dp[102][52][202][10];
string s;
int dfs(int st,int rem,int now,int last)
{
  if(rem<0)return -1e8;
  if(st==s.size())
  {
    if(rem==0)return now;
    else return -1e8;
  }
  int here=-1e8;
  if(dp[st][rem][now+100][last+3]!=-1)return dp[st][rem][now+100][last+3];
  if(last==0||last==1)
  {
    if(s[st]=='F')
    {
      here=max(here,dfs(st+1,rem,now+1,1));
      here=max(here,dfs(st+1,rem-1,now,-1));
      here=max(here,dfs(st,rem-1,now,-1));
    }
    else
    {
      here=max(here,dfs(st+1,rem,now,-1));
      here=max(here,dfs(st+1,rem-1,now+1,1));
      here=max(here,dfs(st,rem-1,now,1));
    }
  }
  else
  {
    if(s[st]=='F')
    {
      here=max(here,dfs(st+1,rem,now-1,-1));
      here=max(here,dfs(st+1,rem-1,now,1));
      here=max(here,dfs(st,rem-1,now,1));
    }
    else
    {
      here=max(here,dfs(st+1,rem,now,1));
      here=max(here,dfs(st+1,rem-1,now-1,-1));
      here=max(here,dfs(st,rem-1,now,-1));
    }
  }
  return dp[st][rem][now+100][last+3]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s>>n;
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,n,0,0)<<endl;
   return 0;
}