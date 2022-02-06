/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/05/2018 21:16                        
*  solution_verdict: Wrong answer on test 17                 language: GNU C++14                               
*  run_time: 122 ms                                          memory_used: 62800 KB                             
*  problem: https://codeforces.com/contest/67/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e3,inf=1e6;
int a,b,c,d;string x,y;
int dp[N+2][N+2];
int dfs(int i,int j)
{
   if(i==x.size()&&j==y.size())return 0;
  if(i==x.size())return a*(y.size()-j);
  if(j==y.size())return b*(x.size()-i);
   if(dp[i][j]!=-1)return dp[i][j];
   int now=inf;
   /// go go go
  if(x[i]==y[j])
    now=min(now,dfs(i+1,j+1));
   ///insert
  now=min(now,a+dfs(i,j+1));
   ///delete
  now=min(now,b+dfs(i+1,j));
   ///replace
  now=min(now,c+dfs(i+1,j+1));
   ///now the mighty swap
  if(i<x.size()-1&&j<y.size()-1&&x[i+1]==y[j])
  {
    for(int k=j+1;k<y.size();k++)
    {
      if(y[k]==x[i])
      {
        now=min(now,d+a*(k-j-1)+dfs(i+2,k+1));
        break;
      }
    }
  }
  return dp[i][j]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>a>>b>>c>>d;cin>>x>>y;
   memset(dp,-1,sizeof(dp));
   cout<<dfs(0,0)<<endl;
   return 0;
}