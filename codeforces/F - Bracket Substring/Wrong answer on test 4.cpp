/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2018 18:59                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/1015/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const int inf=1e8;
const int N=2e2;
int mn=inf,n,cnt;
long dp[N+2][N+2][3];
string s;
long dfs(int ii,int bl,int f)
{
  if(ii==n&&bl==0&&f==1)return 1;
  if(ii>=n)return 0;
   if(dp[ii][bl][f]!=-1)return dp[ii][bl][f];
   long here=0;
   if(bl+mn>=0&&f==0)
    here=(here+dfs(ii+s.size(),bl+cnt,1))%mod;
  here=(here+dfs(ii+1,bl+1,f))%mod;
  if(bl)here=(here+dfs(ii+1,bl-1,f))%mod;
   return dp[ii][bl][f]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);
   cin>>n>>s;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='(')cnt++;
    else cnt--;
    mn=min(mn,cnt);
  }
  n+=n;
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,0,0)<<endl;
  return 0;
}