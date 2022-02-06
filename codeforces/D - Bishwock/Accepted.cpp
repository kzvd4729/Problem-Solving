/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2018 17:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/991/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
string s[2];
int l,dp[N+2][2][2];
int dfs(int st,int one,int two)
{
  if(dp[st][one][two]!=-1)return dp[st][one][two];
  if(st>=l)return 0;
  char mat[2][2];
  mat[0][0]=s[0][st];
  if(one)mat[0][0]='X';
  mat[1][0]=s[1][st];
  if(two)mat[1][0]='X';
  mat[0][1]=s[0][st+1];
  mat[1][1]=s[1][st+1];
   int ret=0;
   if(mat[0][0]=='0'&&mat[0][1]=='0'&&mat[1][0]=='0')
    ret=max(ret,1+dfs(st+1,1,0));
  if(mat[0][0]=='0'&&mat[0][1]=='0'&&mat[1][1]=='0')
    ret=max(ret,1+dfs(st+2,0,0));
  if(mat[0][1]=='0'&&mat[1][0]=='0'&&mat[1][1]=='0')
    ret=max(ret,1+dfs(st+2,0,0));
  if(mat[0][0]=='0'&&mat[1][0]=='0'&&mat[1][1]=='0')
    ret=max(ret,1+dfs(st+1,0,1));
  ret=max(ret,dfs(st+1,0,0));
   return dp[st][one][two]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s[0]>>s[1];
  l=s[0].size();
  s[0].push_back('X');
  s[1].push_back('X');
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,0,0)<<endl;
   return 0;
}