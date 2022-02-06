/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/14/2019 21:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 64600 KB                             
*  problem: https://codeforces.com/contest/903/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int cost[4],n,dp[1000+2][4][16][16][16],msk[1000+2];
string mt[4];
int dfs(int cl,int rw,int a,int b,int c)
{
  if(rw==4)
  {
    if((a&msk[cl]))return inf;
    return dfs(cl+1,0,b,c,15);
  }
  if(cl==n)return 0;
  if(dp[cl][rw][a][b][c]!=-1)return dp[cl][rw][a][b][c];
   int now=dfs(cl,rw+1,a,b,c);
   if(rw==0)now=min(now,cost[3]+dfs(cl+1,0,0,0,0));
  int ta=a,tb=b,tc=c,l=4;if(rw==0)l--;
  for(int j=rw;j<l;j++)
  {
    if(j-rw==0)
    {
      if(ta&(1<<j))ta^=(1<<j);
      now=min(now,cost[0]+dfs(cl,rw+1,ta,tb,tc));
    }
    else if(j-rw==1)
    {
      if(ta&(1<<j))ta^=(1<<j);
      if(tb&(1<<j))tb^=(1<<j);
      if(tb&(1<<(j-1)))tb^=(1<<(j-1));
      now=min(now,cost[1]+dfs(cl,rw+1,ta,tb,tc));
    }
    else
    {
      if(ta&(1<<j))ta^=(1<<j);
      if(tb&(1<<j))tb^=(1<<j);
      if(tc&(1<<j))tc^=(1<<j);
      if(tc&(1<<(j-1)))tc^=(1<<(j-1));
      if(tc&(1<<(j-2)))tc^=(1<<(j-2));
      now=min(now,cost[2]+dfs(cl,rw+1,ta,tb,tc));
    }
  }
  return dp[cl][rw][a][b][c]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;for(int i=0;i<4;i++)cin>>cost[i];
  for(int i=0;i<4;i++)
    cin>>mt[i];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<4;j++)
      if(mt[j][i]=='*')msk[i]|=(1<<j);
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,0,15,15,15)<<endl;
  return 0;
}