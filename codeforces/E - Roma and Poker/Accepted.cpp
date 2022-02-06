/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2019 20:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7900 KB                              
*  problem: https://codeforces.com/contest/803/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int n,k,dp[N+2][N+N+2];string s;
int dfs(int i,int j)
{
  if(i==s.size())
  {
    if(abs(j)==k)return dp[i][j+N]=1;
    else return dp[i][j+N]=0;
  }
  if(abs(j)>=k)return dp[i][j+N]=0;
  if(dp[i][j+N]!=-1)return dp[i][j+N];
  int now=0;
  if(s[i]=='?')
  {
    now|=dfs(i+1,j+1);
    now|=dfs(i+1,j-1);
    now|=dfs(i+1,j);
  }
  else
  {
    if(s[i]=='W')now=dfs(i+1,j+1);
    else if(s[i]=='L')now=dfs(i+1,j-1);
    else now=dfs(i+1,j);
  }
  return dp[i][j+N]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;cin>>s;memset(dp,-1,sizeof(dp));
  if(!dfs(0,0))cout<<"NO"<<endl,exit(0);
  int i=0,j=N;
  while(n--)
  {
    if(dp[i+1][j+1]==1)
    {
      cout<<'W';i++,j++;
    }
    else if(dp[i+1][j]==1)
    {
      cout<<'D';i++;
    }
    else if(dp[i+1][j-1]==1)
    {
      cout<<'L';i++,j--;
    }
    //else assert(0);
  }
  cout<<endl;
  return 0;
}