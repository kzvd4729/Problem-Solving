/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2020 18:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 389 ms                                          memory_used: 196000 KB                            
*  problem: https://codeforces.com/contest/611/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3,mod=1e9+7;
string s;int n,mm[N+2][N+2];
int dfs(int i,int j)
{
  if(s[i]!=s[j])return 0;
  if(mm[i][j]!=-1)return mm[i][j];
  return mm[i][j]=1+dfs(i+1,j+1);
}
bool ret(int i,int j,int k)
{
  if(i<=0)return false;
  if(s[i]=='0')return false;
  int mt=dfs(i,j);
  if(mt>=k)return false;
  return s[i+mt]<s[j+mt];
}
int dp[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>s;s="#"+s+"&";
   memset(mm,-1,sizeof(mm));
   for(int i=0;i<=n;i++)dp[0][i]=1;
  for(int i=1;i<=n;i++)
  {
    for(int l=1;l<=n;l++)
    {
      dp[i][l]=dp[i][l-1];
      if(i-l<0||s[i-l+1]=='0')continue;
      dp[i][l]=(dp[i][l]+dp[i-l][l-1])%mod;
      if(ret(i-l-l+1,i-l+1,l))dp[i][l]=(dp[i][l]+dp[i-l][l]-dp[i-l][l-1])%mod;
       if(dp[i][l]<0)dp[i][l]+=mod;
    }
  }
  cout<<dp[n][n]<<endl;
  return 0;
}