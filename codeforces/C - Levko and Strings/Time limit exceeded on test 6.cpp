/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/20/2019 19:03                        
*  solution_verdict: Time limit exceeded on test 6           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 61000 KB                             
*  problem: https://codeforces.com/contest/360/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
const long mod=1e9+7;
int n,k,dp[N+2][N+2];
string s;
map<pair<int,int>,int>mp[N+2];
long dfs(int i,int j,int e)
{
  if(j>k)return 0;
  if(i==n)return j==k;
  if(mp[i].find({j,e})!=mp[i].end())return mp[i][{j,e}];
  int c=s[i]-'a';long now=0;
  now+=c*dfs(i+1,j,0);
  now+=dfs(i+1,j,e+1);
  now+=(25-c)*dfs(i+1,j+(n-i)*(e+1),0);
  now%=mod;
  return mp[i][{j,e}]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k>>s;memset(dp,-1,sizeof(dp));
  cout<<dfs(0,0,0)<<endl;
    return 0;
}