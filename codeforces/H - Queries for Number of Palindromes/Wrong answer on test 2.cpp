/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/14/2018 02:32                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 622 ms                                          memory_used: 97900 KB                             
*  problem: https://codeforces.com/contest/245/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
int dp[5002][5002];
int dfs(int lo,int hi)
{
  if(lo>hi)return 0;
  if(dp[lo][hi]!=-1)return dp[lo][hi];
  if(s[lo]==s[hi])
    return dp[lo][hi]=1+dfs(lo+1,hi)+dfs(lo,hi-1)-dfs(lo+1,hi-1);
  return dp[lo][hi]=dfs(lo+1,hi)+dfs(lo,hi-1)-dfs(lo+1,hi-1);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  int q;cin>>q;
  memset(dp,-1,sizeof(dp));
   while(q--)
  {
    int lt,rt;cin>>lt>>rt;
    cout<<dfs(lt-1,rt-1)<<endl;
  }
  return 0;
}