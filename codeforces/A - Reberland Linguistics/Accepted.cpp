/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/26/2019 00:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/666/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
string s;int n,dp[N+10][5];
bool dfs(int i,int l)
{
  if(i==n)return dp[i][l]=true;int now=0;
  if(dp[i][l]!=-1)return dp[i][l];
  if(l==2)
  {
    if(i+1<n&&(s[i]!=s[i-2]||s[i+1]!=s[i-1]))
      now|=dfs(i+2,2);
    if(i+2<n)
      now|=dfs(i+3,3);
  }
  else
  {
    if(i+1<n)
      now|=dfs(i+2,2);
    if(i+2<n&&(s[i]!=s[i-3]||s[i+1]!=s[i-2]||s[i+2]!=s[i-1]))
      now|=dfs(i+3,3);
  }
  return dp[i][l]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>s;n=s.size();
  memset(dp,-1,sizeof(dp));
  dfs(7,2);
  for(int i=8;i<=n;i++)
    dfs(i,2),dfs(i,3);
  set<string>st;
  for(int i=5;i<=n;i++)
  {
    if(dp[i+2][2]==1)
      st.insert(s.substr(i,2));
    if(dp[i+3][3]==1)
      st.insert(s.substr(i,3));
  }
  cout<<st.size()<<endl;
  for(auto x:st)
    cout<<x<<endl;
  return 0;
}